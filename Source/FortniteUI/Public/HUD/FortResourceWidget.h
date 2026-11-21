// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "Building/BuildingTypes.h"
#include "FortResourceWidget.generated.h"

class UCommonNumericTextBlock;
class UFortLazyImage;
class UFortResourceItemDefinition;

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortResourceWidget : public UCommonUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void SetResourceCost(const int32 ResourceCost);

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditInstanceOnly, Category="Design Time", meta=(DisplayName="Is Resource Visible"))
	bool bDesignTime_IsResourceVisible;
#endif

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnIsActiveResourceChanged(const bool bIsActiveResource);

	UFUNCTION(BlueprintImplementableEvent)
	void OnResourceCostSet(const int32 ResourceCount, const int32 ResourceCost, const bool bHasInfiniteResources);

	UFUNCTION(BlueprintImplementableEvent)
	void OnResourceCountUpdated(const int32 CurrentCount, const int32 MaxCount, const bool bHasInfiniteResources);

private:
	UPROPERTY(BlueprintReadOnly, Export, Category="FortResourceWidget", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UFortLazyImage> LazyImage_ResourceIcon;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortResourceWidget", meta=(AllowPrivateAccess, BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonNumericTextBlock> NumericText_ResourceCount;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortResourceWidget", meta=(AllowPrivateAccess, BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonNumericTextBlock> NumericText_ResourceCost;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortResourceWidget", meta=(AllowPrivateAccess, ExposeOnSpawn))
	TObjectPtr<UFortResourceItemDefinition> ItemDefinition;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortResourceWidget", meta=(AllowPrivateAccess, ExposeOnSpawn))
	TEnumAsByte<EFortResourceType::Type> ResourceType;

	UPROPERTY(EditInstanceOnly, Category="FortResourceWidget")
	bool bCanUseShorthandCount;

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="Design Time", meta=(DisplayName="Is Active Resource"))
	bool bDesignTime_IsActiveResource;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="Design Time", meta=(ClampMin="0", DisplayName="Resource Count"))
	int32 DesignTime_ResourceCount;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="Design Time", meta=(DisplayName="Has Infinite Resources"))
	bool bDesignTime_HasInfiniteResources;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="Design Time", meta=(ClampMin="0", DisplayName="Max Stack Size"))
	int32 DesignTime_MaxStackSize;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="Design Time", meta=(ClampMin="0", DisplayName="Resource Cost"))
	int32 DesignTime_ResourceCost;
#endif

};

