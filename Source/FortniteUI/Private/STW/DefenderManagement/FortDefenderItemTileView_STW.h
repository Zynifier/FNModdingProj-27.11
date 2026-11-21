// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ItemTiles/FortItemTileView.h"
#include "FortDefenderItemTileView_STW.generated.h"

class UFortDefenderConfigPanel_STW;

UCLASS(BlueprintType)
class UFortDefenderItemTileView_STW : public UFortItemTileView
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadWrite, Export, Category="Defenders")
	TWeakObjectPtr<UFortDefenderConfigPanel_STW> DefenderConfigPanel;

};

