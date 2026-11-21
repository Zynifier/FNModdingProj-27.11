// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonPoolableWidgetInterface.h"
#include "CommonUserWidget.h"
#include "GameplayTagContainer.h"
#include "FortUITypes.h"
#include "FortAttributeListItem_NUI.generated.h"

UCLASS(Abstract, MinimalAPI, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortAttributeListItem_NUI : public UCommonUserWidget, public ICommonPoolableWidgetInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Fort Attribute List Item")
	void ClearPreview();

	UFUNCTION(BlueprintImplementableEvent, Category="Fort Attribute List Item")
	void DisplayAttributeChanged();

	UFUNCTION(BlueprintPure, Category="Fort Attribute List Item", meta=(DisplayName="Get Current Attribute"))
	void GetCurrentAttributeCopy(FFortDisplayAttribute& OutDisplayAttribute) const;

	UFUNCTION(BlueprintPure, Category="Fort Attribute List Item", meta=(DisplayName="Get Display Attribute"))
	void GetDisplayAttributeCopy(FFortDisplayAttribute& OutDisplayAttribute) const;

	UFUNCTION(BlueprintPure, Category="Fort Attribute List Item", meta=(DisplayName="Get Preview Attribute"))
	void GetDisplayPreviewCopy(FFortDisplayAttribute& OutPreviewAttribute) const;

	UFUNCTION(BlueprintPure, Category="Fort Attribute List Item")
	bool HasPreviewAttribute() const;

	UFUNCTION(BlueprintImplementableEvent, Category="Fort Attribute List Item")
	void PreviewEnded();

	UFUNCTION(BlueprintImplementableEvent, Category="Fort Attribute List Item")
	void PreviewStarted();

	UFUNCTION(BlueprintCallable, Category="Fort Attribute List Item")
	void SetDisplayAttribute(const FFortDisplayAttribute& InDisplayAttribute);

	UFUNCTION(BlueprintCallable, Category="Fort Attribute List Item")
	void SetPreviewAttribute(const FFortDisplayAttribute& InPreviewAttribute);

	UFUNCTION(BlueprintImplementableEvent, Category="Fort Attribute List Item")
	void ValueChanged(float Delta);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Fort Attribute List Item")
	bool bHoverEnabled;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Fort Attribute List Item")
	FGameplayTag StatTag;

};

