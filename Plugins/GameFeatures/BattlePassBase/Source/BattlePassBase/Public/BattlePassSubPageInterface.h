// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BattlePassSubPageInterface.generated.h"

USTRUCT()
struct BATTLEPASSBASE_API FBattlePassCoverPageParams
{
	GENERATED_BODY()

};

USTRUCT()
struct BATTLEPASSBASE_API FBattlePassEntrySelectedParams
{
	GENERATED_BODY()

};

UINTERFACE()
class BATTLEPASSBASE_API UBattlePassSubPageInterface : public UInterface
{
	GENERATED_BODY()
};

class BATTLEPASSBASE_API IBattlePassSubPageInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent)
	void OnEnterSubPage();

};

