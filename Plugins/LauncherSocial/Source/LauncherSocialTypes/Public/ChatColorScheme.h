// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/Color.h"
#include "ChatColorScheme.generated.h"

USTRUCT()
struct FChatColorScheme
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Appearance")
	FLinearColor TimeStampColor;

	UPROPERTY(EditAnywhere, Category="Appearance")
	FLinearColor DefaultChatColor;

	UPROPERTY(EditAnywhere, Category="Appearance")
	FLinearColor WhisperChatColor;

	UPROPERTY(EditAnywhere, Category="Appearance")
	FLinearColor GlobalChatColor;

	UPROPERTY(EditAnywhere, Category="Appearance")
	FLinearColor FounderChatColor;

	UPROPERTY(EditAnywhere, Category="Appearance")
	FLinearColor GameChatColor;

	UPROPERTY(EditAnywhere, Category="Appearance")
	FLinearColor TeamChatColor;

	UPROPERTY(EditAnywhere, Category="Appearance")
	FLinearColor PartyChatColor;

	UPROPERTY(EditAnywhere, Category="Appearance")
	FLinearColor AdminChatColor;

	UPROPERTY(EditAnywhere, Category="Appearance")
	FLinearColor GameAdminChatColor;

	UPROPERTY(EditAnywhere, Category="Appearance")
	FLinearColor WhisperHyperlinkChatColor;

	UPROPERTY(EditAnywhere, Category="Appearance")
	FLinearColor GlobalHyperlinkChatColor;

	UPROPERTY(EditAnywhere, Category="Appearance")
	FLinearColor FounderHyperlinkChatColor;

	UPROPERTY(EditAnywhere, Category="Appearance")
	FLinearColor GameHyperlinkChatColor;

	UPROPERTY(EditAnywhere, Category="Appearance")
	FLinearColor TeamHyperlinkChatColor;

	UPROPERTY(EditAnywhere, Category="Appearance")
	FLinearColor PartyHyperlinkChatColor;

	UPROPERTY(EditAnywhere, Category="Appearance")
	FLinearColor EnemyColor;

	UPROPERTY(EditAnywhere, Category="Appearance")
	FLinearColor FriendlyColor;

};

