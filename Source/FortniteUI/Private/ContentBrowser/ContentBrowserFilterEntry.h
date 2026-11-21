// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonButtonLegacy.h"
#include "ContentBrowserFilterEntry.generated.h"

class UCommonTextBlock;
class UContentBrowserFilterEntry;
class UContentBrowserTag;
class UObject;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FFilterEnabledDelegate, bool, bIsEnabled, UObject*, ListItemObject);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FFilterSelectedDelegate, bool, bIsSelected, UContentBrowserFilterEntry*, Entry);

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UContentBrowserFilterEntry : public UCommonButtonLegacy
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	bool IsFilterActive() const;

	UFUNCTION(BlueprintCallable)
	void SetIsFilterActive(bool bInFilterActive);

	UFUNCTION(BlueprintCallable)
	void UpdateButtonText();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void UpdateCheckMarkState(bool bIsChecked);

	UPROPERTY(BlueprintAssignable)
	FFilterEnabledDelegate OnFilterEnabled;

	UPROPERTY(BlueprintAssignable)
	FFilterSelectedDelegate OnFilterSelected;

protected:
	UPROPERTY(BlueprintReadOnly, Export, Category="ContentBrowserFilterEntry", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> TextBlock_FilterName;

	UPROPERTY(BlueprintReadOnly, Category="ContentBrowserFilterEntry")
	bool bFilterActive;

	UPROPERTY(BlueprintReadOnly, Category="ContentBrowserFilterEntry")
	TObjectPtr<UContentBrowserTag> Tag;

	UPROPERTY(EditAnywhere, Category="ContentBrowserFilterEntry")
	FText ButtonText;

};

