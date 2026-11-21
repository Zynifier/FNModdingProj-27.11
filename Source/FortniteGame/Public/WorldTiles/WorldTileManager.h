// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Items/FortLootQuotaData.h"
#include "WorldTileManager.generated.h"

class AFortWorldManager;

USTRUCT()
struct FFortTileLootData
{
	GENERATED_BODY()

public:
	UPROPERTY(meta=(ArraySizeEnum="/Script/FortniteGame.ELootQuotaLevel"))
	FFortLootQuotaData LootQuotas[18];

	UPROPERTY(meta=(ArraySizeEnum="/Script/FortniteGame.ELootQuotaLevel"))
	int32 LootDrops[18];

};

UCLASS()
class UWorldTileManager : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	TObjectPtr<AFortWorldManager> WorldManager;

};

