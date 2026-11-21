// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Pawns/FortAIPawn.h"
#include "FortPawn_Taker.generated.h"

class ABuildingActor;
class UMaterialInterface;

USTRUCT()
struct FBuildingHitTime
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TObjectPtr<ABuildingActor> HitBuilding;

};

UCLASS(BlueprintType, Blueprintable, HideCategories=("Movement", "Actor", "Movement", "Actor", "Movement", "Game|Damage", "Navigation"))
class AFortPawn_Taker : public AFortAIPawn
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category="MaterialParameters")
	void OverrideMaterialAndCopyParametersOnCharacterMesh(UMaterialInterface* NewMaterialToApply);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category="MaterialParameters")
	void RestorePreviousMaterialOnCharacterMesh(float ScalarValue);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category="MaterialParameters")
	void SetScalarParameterOnAllCharacterMIDs(FName ParameterName, float ScalarValue);

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Effects")
	float SlowShackleScale;

	UPROPERTY(EditAnywhere, Category="TakerPortal")
	uint8 bUseClimbLinks : 1;

	UPROPERTY(Transient)
	TArray<FBuildingHitTime> BuildingCollisions;

};

