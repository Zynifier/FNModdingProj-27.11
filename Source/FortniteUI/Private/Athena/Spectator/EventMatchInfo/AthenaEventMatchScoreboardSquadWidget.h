// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/IUserObjectListEntry.h"
#include "Athena/Spectator/EventMatchInfo/AthenaEventMatchSquadWidgetBase.h"
#include "AthenaEventMatchScoreboardSquadWidget.generated.h"

UCLASS(Abstract, BlueprintType, Blueprintable)
class UAthenaEventMatchScoreboardSquadWidget : public UAthenaEventMatchSquadWidgetBase, public IUserObjectListEntry
{
	GENERATED_BODY()

};

