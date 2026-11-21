// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SidecarSys.generated.h"

class USidecarDss;
class USidecarInventorySys;

UCLASS(Config=Engine)
class SIDECARSYS_API USidecarSys : public UObject
{
	GENERATED_BODY()

private:
	UPROPERTY()
	TObjectPtr<USidecarDss> SidecarDss;

	UPROPERTY()
	TObjectPtr<USidecarInventorySys> SidecarInventory;

};

