// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ItemTiles/FortItemTileView.h"
#include "FortDefenderItemTileView.generated.h"

class UFortDefenderConfigPanel;

UCLASS(BlueprintType)
class UFortDefenderItemTileView : public UFortItemTileView
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadWrite, Export, Category="Defenders")
	TWeakObjectPtr<UFortDefenderConfigPanel> DefenderConfigPanel;

};

