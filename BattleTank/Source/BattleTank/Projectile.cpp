// Fill out your copyright notice in the Description page of Project Settings.

#include "Projectile.h"

// Sets default values
AProjectile::AProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	movmentComponent = CreateDefaultSubobject<UProjectileMovementComponent>(FName("Projectilemovment"));
	staticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(FName("StaticMeshComponent"));

	SetRootComponent(staticMeshComponent);
	
	LaunchBlast = CreateDefaultSubobject<UParticleSystemComponent>(FName("LaunchBlast"));
	LaunchBlast->AttachToComponent(RootComponent,FAttachmentTransformRules::KeepRelativeTransform);

	ImpactBlast = CreateDefaultSubobject<UParticleSystemComponent>(FName("ImpactBlast"));
	ImpactBlast->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);

	RadialForce = CreateDefaultSubobject<URadialForceComponent>(FName("RadialForce"));
	RadialForce->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);


	staticMeshComponent->SetNotifyRigidBodyCollision(true);
	movmentComponent->bAutoActivate = false;
}

// Called when the game starts or when spawned
void AProjectile::BeginPlay()
{
	Super::BeginPlay();
	staticMeshComponent->OnComponentHit.AddDynamic(this, &AProjectile::OnCompHit);
	staticMeshComponent->SetNotifyRigidBodyCollision(true);
}

// Called every frame
void AProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AProjectile::LaunchProjectile(float Speed)
{
	ImpactBlast->Deactivate();
	movmentComponent->SetVelocityInLocalSpace(FVector::ForwardVector * Speed);
	movmentComponent->Activate();

}

void AProjectile::OnCompHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit) {
	
	//UE_LOG(LogTemp, Warning, TEXT("Hi Actor Name %s"), *Hit.GetActor()->GetName())
	LaunchBlast->Deactivate();
	ImpactBlast->Activate();
	
	RadialForce->FireImpulse();

	FTimerHandle Timer;

	GetWorld()->GetTimerManager().SetTimer(Timer,this, &AProjectile::OnTimeExpired, ProjectileCleanUpDelay,false);

	

	UGameplayStatics::ApplyRadialDamage(this, ProjectileDamage, staticMeshComponent->GetComponentLocation(), RadialForce->Radius,
		UDamageType::StaticClass(), TArray<AActor*>());

}


void AProjectile::OnTimeExpired() {
	Destroy();
}



