// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AI/DebugMinimapData.h"
#include "Athena/AI/FortAthenaAISpawnerDataComponent_DebugBase.h"
#include "FortAthenaAISpawnerDataComponent_AIBotDebug.generated.h"

UCLASS()
class UFortAthenaAISpawnerDataComponent_AIBotDebug : public UFortAthenaAISpawnerDataComponent_DebugBase
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category="Minimap", meta=(AllowPrivateAccess="true"))
	FDebugMinimapData DebugMinimapData;

	UPROPERTY(EditDefaultsOnly, Category="Cheat Config")
	TArray<FString> EditorConsoleCommands;

};

