// Copyright Epic Games, Inc. All Rights Reserved.

#include "Components/FortPawnComponent_SpeechBubble.h"
#include "Net/UnrealNetwork.h"

const FText& UFortPawnComponent_SpeechBubble::GetSpeechBubbleText() const
{
	static FText Dummy;
	return Dummy;
}

void UFortPawnComponent_SpeechBubble::OnRep_SpeechBubbleInfo()
{
}

void UFortPawnComponent_SpeechBubble::StartSpeech(const FGameplayTagQuery FilterTagQuery)
{
}

void UFortPawnComponent_SpeechBubble::StopSpeech()
{
}

void UFortPawnComponent_SpeechBubble::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UFortPawnComponent_SpeechBubble, SpeechBubbleInfo);
}
