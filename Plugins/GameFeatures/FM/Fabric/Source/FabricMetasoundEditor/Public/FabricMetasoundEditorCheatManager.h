// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Player/FortCheatManager.h"
#include "FabricMetasoundEditorCheatManager.generated.h"

UCLASS()
class FABRICMETASOUNDEDITOR_API UFabricMetasoundEditorCheatManager : public UChildCheatManager
{
	GENERATED_BODY()

protected:
	UFUNCTION(Exec)
	void FabricBuildMetasoundToAsset();

};

