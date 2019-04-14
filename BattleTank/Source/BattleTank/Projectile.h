// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "Projectile.generated.h"

UCLASS()
class BATTLETANK_API AProjectile : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AProjectile();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UProjectileMovementComponent* movmentComponent = nullptr;
	UPROPERTY(VisibleAnywhere)
		UStaticMeshComponent* staticMeshComponent = nullptr;
	UPROPERTY(VisibleAnywhere)
		UParticleSystemComponent* LaunchBlast = nullptr;
	UPROPERTY(VisibleAnywhere)
		UParticleSystemComponent* ImpactBlast = nullptr;
	UPROPERTY(VisibleAnywhere)
		URadialForceComponent* RadialForce = nullptr;
	float ProjectileDamage = 20.0f;
	UPROPERTY(VisibleAnywhere)
	float ProjectileCleanUpDelay = 0.1f;

	void LaunchProjectile(float Speed);

	void OnTimeExpired();

	UFUNCTION(BlueprintCallable)
		void OnCompHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);


};
