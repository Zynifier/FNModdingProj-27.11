// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonButtonBase.h"
#include "EmporiumBrowserFilterEntry.generated.h"

class UCommonTextBlock;
class UEmporiumBrowserFilterEntry;
class UEmporiumBrowserTag;
class UObject;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FEmporiumFilterEnabledDelegate, bool, bIsEnabled, UObject*, ListItemObject);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FEmporiumFilterSelectedDelegate, bool, bIsSelected, UEmporiumBrowserFilterEntry*, Entry);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FEmporiumFilterWidgetDestroyedDelegate, UObject*, ListItemObject);

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UEmporiumBrowserFilterEntry : public UCommonButtonBase
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

	UFUNCTION(BlueprintImplementableEvent)
	void UpdateItemCount(int32 ItemCount);

	UPROPERTY(BlueprintAssignable)
	FEmporiumFilterEnabledDelegate OnFilterEnabled;

	UPROPERTY(BlueprintAssignable)
	FEmporiumFilterSelectedDelegate OnFilterSelected;

	UPROPERTY(BlueprintAssignable)
	FEmporiumFilterWidgetDestroyedDelegate OnWidgetDestroyed;

protected:
	UPROPERTY(BlueprintReadOnly, Export, Category="EmporiumBrowserFilterEntry", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> TextBlock_FilterName;

	UPROPERTY(BlueprintReadOnly, Category="EmporiumBrowserFilterEntry")
	bool bFilterActive;

	UPROPERTY(BlueprintReadOnly, Category="EmporiumBrowserFilterEntry")
	TObjectPtr<UEmporiumBrowserTag> Tag;

	UPROPERTY(EditAnywhere, Category="EmporiumBrowserFilterEntry")
	FText ButtonText;

};

