// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Net/Serialization/FastArraySerializer.h"
#include "ScalableFloat.h"
#include "Styling/SlateBrush.h"
#include "Athena/Modifiers/FortAthenaMutator_GameModeBase.h"
#include "Athena/Modifiers/FortAthenaMutator_TeamPawnColor.h"
#include "FortAthenaMutator_Tag.generated.h"

class AFortPlayerControllerAthena;

USTRUCT()
struct FTagTeamInfoEntry : public FFastArraySerializerItem
{
	GENERATED_BODY()

public:
	UPROPERTY()
	uint8 TeamNum;

	UPROPERTY()
	int32 PlayerCount;

	UPROPERTY(NotReplicated)
	int32 PreviousPlayerCount;

};

USTRUCT()
struct FTagTeamInfoArray : public FFastArraySerializer
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TArray<FTagTeamInfoEntry> Entries;

};

UCLASS(MinimalAPI, HideCategories=("Tick", "Replication", "Actor", "LOD", "Cooking", "Mutator", "FortAthenaMutator", "Tick", "Replication", "Actor", "LOD", "Cooking", "Mutator", "FortAthenaMutator", "Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortAthenaMutator_Tag : public AFortAthenaMutator_GameModeBase
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category="Data")
	FScalableFloat TimerLength;

	UPROPERTY(EditAnywhere, Category="Visuals")
	FTeamPawnColor_VisualData RedTeamVisuals;

	UPROPERTY(EditAnywhere, Category="Visuals")
	FTeamPawnColor_VisualData BlueTeamVisuals;

	UPROPERTY(EditDefaultsOnly, Category="FortAthenaMutator_Tag")
	FSlateBrush BlueTeamMapBrush;

	UPROPERTY(EditDefaultsOnly, Category="FortAthenaMutator_Tag")
	FVector2D BlueTeamMapScale;

	UPROPERTY(Replicated)
	float ServerEndTime;

	UPROPERTY()
	uint8 RedTeam;

	UPROPERTY()
	uint8 BlueTeam;

	UPROPERTY()
	uint8 RedTeamSquad;

	UPROPERTY(Replicated)
	FTagTeamInfoArray TagTeamInfo;

	UPROPERTY()
	TArray<TObjectPtr<AFortPlayerControllerAthena>> SeenControllers;

};

