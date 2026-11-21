// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "Engine/DataTable.h"
#include "GameplayEffectTypes.h"
#include "GameplayTagContainer.h"
#include "FortHomebaseNodeGameplayEffectDataTable.generated.h"

class UGameplayEffect;

USTRUCT()
struct FHomebaseNodeGameplayEffectDataTableRow : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="HomebaseNodeGE")
	FGameplayAttribute Attribute;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="HomebaseNodeGE")
	TEnumAsByte<EGameplayModOp::Type> Operation;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="HomebaseNodeGE")
	float Magnitude;

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditDefaultsOnly, Category="HomebaseNodeGE")
	FString ApplicationRequiredTags;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditDefaultsOnly, Category="HomebaseNodeGE")
	FString RequiredSourceTags;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditDefaultsOnly, Category="HomebaseNodeGE")
	FString RequiredTargetTags;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditDefaultsOnly, Category="HomebaseNodeGE")
	FString GrantedTags;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditDefaultsOnly, Category="HomebaseNodeGE")
	FString IgnoreSourceTags;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditDefaultsOnly, Category="HomebaseNodeGE")
	FString AssetTags;
#endif

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="HomebaseNodeGE", meta=(DataTableImportOptional))
	FGameplayTagContainer ApplicationRequiredTagsContainer;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="HomebaseNodeGE", meta=(DataTableImportOptional))
	FGameplayTagContainer RequiredSourceTagsContainer;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="HomebaseNodeGE", meta=(DataTableImportOptional))
	FGameplayTagContainer RequiredTargetTagsContainer;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="HomebaseNodeGE", meta=(DataTableImportOptional))
	FGameplayTagContainer GrantedTagsContainer;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="HomebaseNodeGE", meta=(DataTableImportOptional))
	FGameplayTagContainer IgnoreSourceTagsContainer;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="HomebaseNodeGE", meta=(DataTableImportOptional))
	FGameplayTagContainer AssetTagsContainer;

	UPROPERTY(EditDefaultsOnly, Category="HomebaseNodeGE", meta=(DataTableImportOptional))
	int32 AssociatedGEIdx;

	UPROPERTY(EditDefaultsOnly, Category="HomebaseNodeGE", meta=(DataTableImportOptional))
	int32 AssociatedModifierIdx;

};

UCLASS(MinimalAPI, AutoExpandCategories=("DataTable,ImportOptions"))
class UFortHomebaseNodeGameplayEffectDataTable : public UDataTable
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="GameplayEffects")
	TArray<TSubclassOf<UGameplayEffect>> TemplateAttributeGEs;

};

