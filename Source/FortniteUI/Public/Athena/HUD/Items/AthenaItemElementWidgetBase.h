// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "FortRarityData.h"
#include "FortRarityEnum.h"
#include "AthenaItemElementWidgetBase.generated.h"

class UFortItem;
class UFortItemDefinition;
enum class EFortRarity : uint8;

UCLASS(Abstract, MinimalAPI, NotBlueprintable, meta=(DisableNativeTick))
class UAthenaItemElementWidgetBase : public UCommonUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	const UFortItem* GetItemToRepresent() const;

	UFUNCTION(BlueprintCallable)
	void SetItemToRepresent(const UFortItem* ItemToRepresent);

protected:
	UFUNCTION()
	void HandleItemChanged(bool bItemChanged, bool bAmmoChanged, bool bIngredientsChanged);

	UFUNCTION(BlueprintImplementableEvent)
	void OnItemRarityUpdated(const EFortRarity ItemRarity, const FFortRarityItemData RarityItemData);

	UFUNCTION(BlueprintImplementableEvent)
	void OnPostItemToRepresentChanged(const UFortItem* ItemToRepresent);

	UFUNCTION(BlueprintImplementableEvent)
	void OnPreItemToRepresentChanged(const UFortItem* ItemToRepresent);

private:
#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="Design Time", meta=(DisplayName="Set Item To Represent", DisplayPriority="1"))
	bool bDesignTime_SetItemToRepresent;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="Design Time", meta=(DisplayName="Item Definition To Represent", DisplayPriority="1", EditCondition="bDesignTime_SetItemToRepresent"))
	TObjectPtr<UFortItemDefinition> DesignTime_ItemDefinitionToRepresent;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="Design Time", meta=(ClampMin="0", DisplayName="Item Stack Count", DisplayPriority="1", EditCondition="bDesignTime_SetItemToRepresent"))
	int32 DesignTime_ItemStackCount;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="Design Time", meta=(DisplayName="Set Item Rarity", EditCondition="!bDesignTime_SetItemToRepresent"))
	bool bDesignTime_SetItemRarity;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="Design Time", meta=(DisplayName="Item Rarity", EditCondition="bDesignTime_SetItemRarity"))
	EFortRarity DesignTime_ItemRarity;
#endif

};

