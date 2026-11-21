// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/HitResult.h"
#include "OverlapComponent.generated.h"

class AActor;
class UPrimitiveComponent;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FActorOverlapSignature, AActor*, OverlappedActor, AActor*, OtherActor);

UCLASS(HideCategories=("Object", "Activation", "Components|Activation", "Trigger"), ClassGroup=("Custom"), meta=(BlueprintSpawnableComponent))
class PLAYSPACESYSTEM_API UOverlapComponent : public UStaticMeshComponent
{
	GENERATED_BODY()

protected:
	UFUNCTION()
	virtual void OnBeginActorOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	virtual void OnEndActorOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

};

