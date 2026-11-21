// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "PersistenceFramework/PersistenceFrameworkRootArea.h"
#include "FortPersistenceFrameworkRootAreaWorldForPlayer.generated.h"

UCLASS()
class FORTNITEGAME_API UFortPersistenceFrameworkRootAreaWorldForPlayer : public UPersistenceFrameworkRootArea
{
	GENERATED_BODY()

protected:
	UPROPERTY()
	bool bLogOutDisabled;

	UPROPERTY()
	bool bWaitForLogOut;

};

