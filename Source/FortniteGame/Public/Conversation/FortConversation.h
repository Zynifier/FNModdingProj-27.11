// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Sound/FortFeedbackManager.h"
#include "FortConversation.generated.h"

class UAnimMontage;
class USoundBase;
class UTexture2D;

UENUM()
enum class EFortSentenceAudioPreference : uint8
{
	AudioAsset = 0,
	FeedbackBank = 1,
};

USTRUCT(BlueprintType)
struct FFortSentenceAudio
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortSentenceAudio")
	TSoftObjectPtr<USoundBase> Audio;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortSentenceAudio")
	FFortFeedbackHandle Handle;

};

USTRUCT(BlueprintType)
struct FFortConversationSentence
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortConversationSentence")
	FFortSentenceAudio SpeechAudio;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortConversationSentence")
	FText SpeechText;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortConversationSentence")
	TSoftObjectPtr<UTexture2D> TalkingHeadTexture;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortConversationSentence")
	FText TalkingHeadTitle;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortConversationSentence")
	TSoftObjectPtr<UAnimMontage> AnimMontage;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortConversationSentence")
	float PostSentenceDelay;

	UPROPERTY(EditDefaultsOnly, Category="FortConversationSentence")
	float DisplayDuration;

};

UCLASS(MinimalAPI, BlueprintType, Blueprintable)
class UFortConversation : public UDataAsset
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="FortConversation")
	TArray<FFortConversationSentence> Sentences;

};

