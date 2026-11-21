// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "PersistenceInventoryRequestInterface.h"
#include "SaveFrameworkInventorySys.generated.h"

UCLASS()
class FNONLINEFRAMEWORK_API USaveFrameworkInventorySys : public UObject, public IPersistenceInventoryRequestInterface
{
	GENERATED_BODY()

};

