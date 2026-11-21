// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "PersistenceFramework/PersistenceFrameworkRootArea.h"
#include "PersistenceFramework/PersistenceFrameworkWorldPartInfo.h"
#include "FortPersistenceFrameworkRootAreaWorldPart.generated.h"

UCLASS()
class FORTNITEGAME_API UFortPersistenceFrameworkRootAreaWorldPart : public UPersistenceFrameworkRootArea
{
	GENERATED_BODY()

protected:
	UPROPERTY()
	FPersistenceFrameworkWorldPartInfo WorldPartInfo;

};

