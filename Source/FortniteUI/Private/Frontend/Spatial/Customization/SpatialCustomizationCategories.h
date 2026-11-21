// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Frontend/Spatial/Customization/SpatialCustomizationSubscreenBase.h"
#include "SpatialCustomizationCategories.generated.h"

class UAthenaSpatialCustomizationCategoryEntry;
class UWidgetAnimation;

USTRUCT()
struct FAthenaSpatialCustomizationCategoryGroup
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TArray<TObjectPtr<UAthenaSpatialCustomizationCategoryEntry>> CategoryEntryList;

};

UCLASS(Abstract, BlueprintType, Blueprintable)
class UAthenaSpatialCustomizationCategories : public UAthenaSpatialCustomizationSubscreenBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void AddCategoryGroup(FName CategoryGroup, const TArray<UAthenaSpatialCustomizationCategoryEntry*>& CategoryEntries);

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void BP_OnCategoriesSetup(int32 TotalNumCategoriesFinalized);

	UFUNCTION(BlueprintImplementableEvent)
	void BP_OnCategoryGroupProgress(FName CategoryGroup, int32 NumCategoriesFinalized);

	UFUNCTION(BlueprintImplementableEvent)
	void OnSetCaptureMode(bool bCaptureMode);

private:
	UPROPERTY(BlueprintReadOnly, Transient, Category="AthenaSpatialCustomizationCategories", meta=(AllowPrivateAccess="TRUE", BindWidgetAnim))
	TObjectPtr<UWidgetAnimation> IntroCategories;

	UPROPERTY(Transient)
	TMap<FName, FAthenaSpatialCustomizationCategoryGroup> CategoryGroups;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UAthenaSpatialCustomizationCategoryEntry> LastSelectedCategory;

};

