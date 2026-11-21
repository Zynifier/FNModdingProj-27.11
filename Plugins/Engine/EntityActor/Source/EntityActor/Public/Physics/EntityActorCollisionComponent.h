// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/HitResult.h"
#include "Math/MathFwd.h"
#include "EntityEnableableComponent.h"
#include "EntityActorCollisionComponent.generated.h"

class AActor;
class UPrimitiveComponent;

UENUM(BlueprintType)
namespace ECollisionShapeMode
{
	enum Type
	{
		/*Inherits the collision from a static mesh component.*/
		Mesh = 0,
		/*Use box collision.*/
		Box = 1,
		/*Use capsule collision.*/
		Capsule = 2,
		/*Use sphere collision.*/
		Sphere = 3,
	};
}

UCLASS(meta=(DisplayName="Collision Component"))
class ENTITYACTOR_API UEntityActorCollisionComponent : public UEntityEnableableComponent
{
	GENERATED_BODY()

private:
	UFUNCTION()
	void OnEnabledChanged(bool bIsEnabled);

	UFUNCTION()
	void OnNativeComponentBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void OnNativeComponentEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	UFUNCTION()
	void OnNativeComponentHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

	UFUNCTION()
	void OnRep_CollisionProfileName();

	UFUNCTION()
	void OnRep_PrimitiveComponent();

	UPROPERTY(EditAnywhere, ReplicatedUsing=OnRep_CollisionProfileName, Category="Collision", meta=(DisplayName="Collision Profile Name"))
	FName ShadowVar_CollisionProfileName;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_PrimitiveComponent, Export)
	TSoftObjectPtr<UPrimitiveComponent> PrimitiveComponentCache;

	UPROPERTY(EditAnywhere, Category="Collision", meta=(DisplayName="Collision Mode"))
	TEnumAsByte<ECollisionShapeMode::Type> CollisionShapeMode;

};

