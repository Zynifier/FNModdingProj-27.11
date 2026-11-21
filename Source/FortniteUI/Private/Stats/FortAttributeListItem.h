// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "FortUITypes.h"
#include "FortAttributeListItem.generated.h"

UCLASS(Abstract, BlueprintType, Blueprintable)
class UFortAttributeListItem : public UUserWidget
{
	GENERATED_BODY()

public:
	UFortAttributeListItem(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

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

	UFUNCTION(BlueprintImplementableEvent, Category="Fort Attribute List Item")
	void PreviewEnded();

	UFUNCTION(BlueprintImplementableEvent, Category="Fort Attribute List Item")
	void PreviewStarted();

	UFUNCTION(BlueprintCallable, Category="Fort Attribute List Item")
	bool SetDisplayAttribute(const FFortDisplayAttribute& InDisplayAttribute, FFortDisplayAttribute& DeltaAttribute);

	UFUNCTION(BlueprintCallable, Category="Fort Attribute List Item")
	void SetPreviewAttribute(const FFortDisplayAttribute& InPreviewAttribute);

	UFUNCTION(BlueprintImplementableEvent, Category="Fort Attribute List Item")
	void ValueChanged(float Delta);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Fort Attribute List Item")
	bool bHoverEnabled;

};

