// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Building/BuildingProp.h"
#include "BuildingPropBigHealth.generated.h"

UCLASS(MinimalAPI, BlueprintType, Blueprintable, HideCategories=("Game|Damage"), PrioritizeCategories=("Instance"), SparseClassDataType=BuildingPropActorClassData)
class ABuildingPropBigHealth : public ABuildingProp
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	float GetHealthValuePercent();

	UFUNCTION(BlueprintPure)
	FText GetHealthValueText();

	UFUNCTION()
	void OnRep_BigHealth();

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void SetBigHealth(int64 NewHealth);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void SetBigHealthMax(int64 NewHealth);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_BigHealth, Category="BuildingPropBigHealth")
	int64 BigHealth;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, Category="BuildingPropBigHealth")
	int64 BigHealthMax;

	UPROPERTY(BlueprintReadWrite, Category="BuildingPropBigHealth")
	bool bShowHealthBar;

};

