// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Curie/Elements/Handlers/FortCurieElementHandlers.h"
#include "FortCurieElementHandlersIce.generated.h"

class AActor;
class ABuildingActor;
class AController;
class UPrimitiveComponent;

UCLASS()
class UFortCurieElementAttachConditionHandlerIce : public UFortCurieElementAttachConditionHandler
{
	GENERATED_BODY()

};

UCLASS()
class UFortCurieElementAttachHandlerIce : public UFortCurieElementAttachHandler
{
	GENERATED_BODY()

private:
	UFUNCTION()
	void HandleBuildingDamaged(AActor* DamagedActor, float Damage, AController* InstigatedBy, AActor* DamageCauser, FVector HitLocation, UPrimitiveComponent* FHitComponent, FName BoneName, FVector Momentum);

	UFUNCTION()
	void ResolveBuildingDamage(ABuildingActor* DamagedBuildingActor, AController* InstigatedBy, AActor* DamageCauser);

	UPROPERTY(EditDefaultsOnly, Category="FortCurieElementAttachHandlerIce")
	float MinWaterContentOnDetach;

	UPROPERTY(EditDefaultsOnly, Category="FortCurieElementAttachHandlerIce")
	float ShatterDamageThreshold;

	UPROPERTY()
	TMap<TObjectPtr<ABuildingActor>, float> AggregateDamagePerActor;

};

