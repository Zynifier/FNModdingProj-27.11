// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Pawns/FortPawn.h"
#include "FortPawn_FeedbackAnnouncer.generated.h"

UENUM()
enum class EFortAnnouncerTeamVocalChords : uint8
{
	Team1 = 0,
	// Default vocal chords in PvE and human team 1 in PvP

	Team2 = 1,
	// Human team 2 in PvP

	Max_None = 2,
};

UCLASS(HideCategories=("Actor", "Movement", "Game|Damage", "Navigation"))
class AFortPawn_FeedbackAnnouncer : public AFortPawn
{
	GENERATED_BODY()

};

