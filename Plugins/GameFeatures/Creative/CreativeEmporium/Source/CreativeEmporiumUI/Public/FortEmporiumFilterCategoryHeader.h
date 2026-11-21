// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "FortEmporiumFilterCategoryHeader.generated.h"

class UCommonButtonBase;
class UEmporiumBrowserTag;
class UObject;
class UWidget;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FFilterCategoryActivatedDelegate, bool, bIsExpanded, UObject*, ListItemObject);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FFilterCategoryWidgetDestroyedDelegate, UObject*, ListItemObject);

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortEmporiumFilterCategoryHeader : public UUserWidget
{
	GENERATED_BODY()

public:
	UFortEmporiumFilterCategoryHeader(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

public:
	UFUNCTION(BlueprintImplementableEvent)
	void AddSubcategoryWidget(UWidget* SubcategoryWidget);

	UFUNCTION(BlueprintImplementableEvent)
	void ClearSubcategoryWidgets();

	UFUNCTION(BlueprintImplementableEvent)
	void EnableCategoryExpansion(bool bShow);

	UFUNCTION(BlueprintImplementableEvent)
	void ExpandCategory(bool bExpanded);

	UFUNCTION(BlueprintImplementableEvent)
	UCommonButtonBase* GetCategoryButton() const;

	UFUNCTION(BlueprintNativeEvent)
	TArray<UWidget*> GetSubcategoryWidgets() const;

	UFUNCTION(BlueprintImplementableEvent)
	void UpdateCategoryCount(int32 NewCount, bool bHideIfEmpty);

	UPROPERTY(BlueprintAssignable)
	FFilterCategoryActivatedDelegate OnCategoryActivated;

	UPROPERTY(BlueprintAssignable)
	FFilterCategoryWidgetDestroyedDelegate OnWidgetDestroyed;

protected:
	UFUNCTION(BlueprintCallable)
	void ActivateCategory(bool bExpanded);

	UFUNCTION(BlueprintImplementableEvent)
	void SetCategoryText(const FText& NewButtonText);

	UFUNCTION(BlueprintImplementableEvent)
	void SetSubcategoryCount(int32 NewCount);

	UPROPERTY(BlueprintReadOnly, Category="FortEmporiumFilterCategoryHeader")
	TObjectPtr<UEmporiumBrowserTag> Tag;

};

