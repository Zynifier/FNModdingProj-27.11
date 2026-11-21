// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "FortUIBaseClass.generated.h"

UCLASS(MinimalAPI, HideCategories=("Rendering", "Actor", "Input", "Replication"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortUIBaseClass : public AHUD
{
	GENERATED_BODY()

};

