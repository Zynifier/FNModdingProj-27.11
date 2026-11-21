// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/Modifiers/FortAthenaMutator_BlockEmotes.h"
#include "Net/UnrealNetwork.h"

void AFortAthenaMutator_BlockEmotes::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFortAthenaMutator_BlockEmotes, bGlobalEmoteBlock);
	DOREPLIFETIME(AFortAthenaMutator_BlockEmotes, BlockEmotesWithTags);
	DOREPLIFETIME(AFortAthenaMutator_BlockEmotes, SpecificEmotesToBlock);
}
