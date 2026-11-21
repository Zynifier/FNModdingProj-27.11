// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonButtonBase.h"
#include "FortCreativeRichTextWordButton.generated.h"

class UCommonButtonStyle;
class URichTextBlock;

UCLASS(Abstract, MinimalAPI, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortCreativeRichTextWordButton : public UCommonButtonBase
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent, meta=(BlueprintProtected="true"))
	void OnButtonInitialized();

	UPROPERTY(BlueprintReadOnly, Export, Category="FortCreativeRichTextWordButton", meta=(BindWidget, EditInline="true"))
	URichTextBlock* Rich_Text;

	UPROPERTY(EditDefaultsOnly, Category="FortCreativeRichTextWordButton")
	TSubclassOf<UCommonButtonStyle> ButtonStyle;

	UPROPERTY(BlueprintReadOnly, Category="FortCreativeRichTextWordButton")
	FString RawText;

};

