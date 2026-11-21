// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortHUDElementWidget.h"
#include "FortEventModeEmotesWidget.generated.h"

class UFortMontageItemDefinitionBase;
class URichTextBlock;

UCLASS()
class UFortEventModeEmotesWidget : public UFortHUDElementWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent)
	void OnFocusAvailableChanged(bool bIsFocusAvailable);

	UFUNCTION(BlueprintImplementableEvent)
	void OnFocusStateChanged(bool bIsFocusing);

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Emote")
	TSoftObjectPtr<UFortMontageItemDefinitionBase> Emote1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Emote")
	TSoftObjectPtr<UFortMontageItemDefinitionBase> Emote2;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Emote")
	TSoftObjectPtr<UFortMontageItemDefinitionBase> Emote3;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Emote")
	TArray<TSoftObjectPtr<UFortMontageItemDefinitionBase>> RandomEmotes;

private:
	UPROPERTY(BlueprintReadOnly, Export, Category="FortEventModeEmotesWidget", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<URichTextBlock> Text_Emote1;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortEventModeEmotesWidget", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<URichTextBlock> Text_Emote2;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortEventModeEmotesWidget", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<URichTextBlock> Text_Emote3;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortEventModeEmotesWidget", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<URichTextBlock> Text_EmoteRandom;

};

