// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ScalableFloat.h"
#include "Athena/AI/FortAthenaAIBotSkillSet.h"
#include "FortAthenaAIBotEmoteSkillSet.generated.h"

UCLASS(MinimalAPI)
class UFortAthenaAIBotEmoteDigestedSkillSet : public UFortAthenaAIBotDigestedSkillSet
{
	GENERATED_BODY()

protected:
	UPROPERTY(Transient)
	float InfiniteEmoteMinDuration;

	UPROPERTY(Transient)
	float InfiniteEmoteMaxDuration;

	UPROPERTY(Transient)
	int32 EmotesMaxCount;

	UPROPERTY(Transient)
	float DanceOnKillMaxDistanceFromKillSqr;

	UPROPERTY(Transient)
	float DanceOnKillMaxTimeFromKill;

	UPROPERTY(Transient)
	float DanceOnKillMinTimeFromLastTry;

	UPROPERTY(Transient)
	float DanceOnKillChanceToDanceOnBots;

	UPROPERTY(Transient)
	float DanceOnKillChanceToDanceOnPlayers;

};

UCLASS(MinimalAPI)
class UFortAthenaAIBotEmoteSkillSet : public UFortAthenaAIBotSkillSet
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="Emote", meta=(AllowPrivateAccess="true"))
	FScalableFloat InfiniteEmoteMinDuration;

	UPROPERTY(EditDefaultsOnly, Category="Emote", meta=(AllowPrivateAccess="true"))
	FScalableFloat InfiniteEmoteMaxDuration;

	UPROPERTY(EditDefaultsOnly, Category="Dance On Kill", meta=(AllowPrivateAccess="true"))
	FScalableFloat DanceOnKillMaxDistanceFromKill;

	UPROPERTY(EditDefaultsOnly, Category="Dance On Kill", meta=(AllowPrivateAccess="true"))
	FScalableFloat DanceOnKillMaxTimeFromKill;

	UPROPERTY(EditDefaultsOnly, Category="Dance On Kill", meta=(AllowPrivateAccess="true"))
	FScalableFloat DanceOnKillMinTimeFromLastTry;

	UPROPERTY(EditDefaultsOnly, Category="Dance On Kill", meta=(AllowPrivateAccess="true"))
	FScalableFloat DanceOnKillChanceToDanceOnBots;

	UPROPERTY(EditDefaultsOnly, Category="Dance On Kill", meta=(AllowPrivateAccess="true"))
	FScalableFloat DanceOnKillChanceToDanceOnPlayers;

};

