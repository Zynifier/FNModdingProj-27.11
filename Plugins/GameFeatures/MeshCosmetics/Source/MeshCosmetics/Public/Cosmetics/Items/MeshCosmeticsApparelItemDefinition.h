// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Items/FortApparelItemDefinitionStubs.h"
#include "Schema/MeshCosmeticsLayoutSchema.h"
#include "MeshCosmeticsApparelItemDefinition.generated.h"

class UCustomizableObject;

USTRUCT(BlueprintType)
struct FApparelCustomizableItemReference
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Apparel")
	FString GroupName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Apparel")
	FString ValueName;

};

UCLASS(MinimalAPI, HideCategories=("Sacrifice", "Conversion", "AccountItem", "InventoryLimit", "Rating", "Level", "Tooltips", "Functionality", "FortItemDefinition"))
class UMeshCosmeticsApparelItemDefinition : public UFortApparelItemDefinition
{
	GENERATED_BODY()

protected:
#if WITH_EDITOR
	UFUNCTION(Exec, Category="MeshCosmetics", meta=(CallInEditor="true"))
	void TryDetermineSlotType();
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="MeshCosmetics")
	TSoftObjectPtr<UCustomizableObject> ApparelObject;
#endif

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="MeshCosmetics")
	FCosmeticSlotSelector SlotValidWithin;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Apparel")
	FApparelCustomizableItemReference Parameter;

};

