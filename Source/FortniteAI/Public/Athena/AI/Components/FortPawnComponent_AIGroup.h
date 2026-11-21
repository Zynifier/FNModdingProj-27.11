// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Components/FortPawnComponent.h"
#include "FortPawnComponent_AIGroup.generated.h"

class AActor;
class AController;
class UPrimitiveComponent;

UCLASS(BlueprintType, Blueprintable, HideCategories=("Trigger", "PhysicsVolume"), meta=(BlueprintSpawnableComponent))
class FORTNITEAI_API UFortPawnComponent_AIGroup : public UFortPawnComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="AIGroup")
	void RemoveFromCurrentGroup();

private:
	UFUNCTION()
	void OnGroupMemberDied(AActor* DamagedActor, float Damage, AController* InstigatedBy, AActor* DamageCauser, FVector HitLocation, UPrimitiveComponent* FHitComponent, FName BoneName, FVector Momentum);

	UPROPERTY(EditDefaultsOnly, Category="Group Component")
	bool bCanBeGroupLeader;

	UPROPERTY(Transient)
	int32 GroupID;

};

