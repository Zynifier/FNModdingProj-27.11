// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Building/BuildingProp.h"
#include "BuildingProp_DestructionObject.generated.h"

class ABuildingProp_DestructionObject;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnBuildingAttributeSetHealthChangedSignature, ABuildingProp_DestructionObject*, DestructionObject, float, Health);

UCLASS(HideCategories=("Game|Damage"), PrioritizeCategories=("Instance"), SparseClassDataType=BuildingPropActorClassData)
class ABuildingProp_DestructionObject : public ABuildingProp
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintAssignable)
	FOnBuildingAttributeSetHealthChangedSignature OnBuildingAttributeSetHealthChangedDelegate;

protected:
	UFUNCTION(BlueprintPure)
	FText GetObjectiveNameText(const int32 ObjectiveNameIndex) const;

	UPROPERTY(EditDefaultsOnly, Category="BuildingProp_DestructionObject")
	TArray<FText> ObjectiveNameTexts;

	UPROPERTY(EditDefaultsOnly, Category="BuildingProp_DestructionObject")
	FText ObjectiveTextTemplate;

	UPROPERTY(EditDefaultsOnly, Category="BuildingProp_DestructionObject")
	FText ObjectiveText;

private:
	UFUNCTION()
	void OnBuildingAttributeSetHealthChanged();

};

