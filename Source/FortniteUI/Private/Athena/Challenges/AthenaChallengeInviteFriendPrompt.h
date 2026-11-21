// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AthenaChallengeInviteFriendPrompt.generated.h"

class URichTextBlock;

UCLASS(Abstract, BlueprintType, Blueprintable)
class UAthenaChallengeInviteFriendPrompt : public UUserWidget
{
	GENERATED_BODY()

public:
	UAthenaChallengeInviteFriendPrompt(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

private:
	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaChallengeInviteFriendPrompt", meta=(AllowPrivateAccess, BindWidgetOptional, EditInline="true"))
	TObjectPtr<URichTextBlock> RichText_InviteFriendMessage;

};

