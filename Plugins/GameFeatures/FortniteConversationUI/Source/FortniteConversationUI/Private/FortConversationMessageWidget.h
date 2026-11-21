// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "FortConversationMessageWidget.generated.h"

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortConversationMessageWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UFortConversationMessageWidget(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

public:
	UFUNCTION(BlueprintCallable, Category="Conversation")
	void SetPreviewMessage(const FText& MessageToSet);

protected:
	UFUNCTION(BlueprintImplementableEvent, Category="Cosmetic")
	void OnMainMessageSet(const FText& NPCName, const FText& MessageBody);

	UFUNCTION(BlueprintImplementableEvent, Category="Cosmetic")
	void OnMessageHidden();

	UFUNCTION(BlueprintImplementableEvent, Category="Cosmetic")
	void OnMessageShown();

	UFUNCTION(BlueprintImplementableEvent, Category="Cosmetic")
	void OnPreviewMessageSet(const FText& PreviewText);

};

