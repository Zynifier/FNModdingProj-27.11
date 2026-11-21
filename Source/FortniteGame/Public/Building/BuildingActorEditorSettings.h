// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"
#include "BuildingActorEditorSettings.generated.h"

UCLASS(Config=Editor, MinimalAPI)
class UBuildingActorEditorSettings : public UDeveloperSettings
{
	GENERATED_BODY()

protected:
#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Config, Category="Material")
	bool bWarnAboutMaterial0Override;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Config, Category="Material")
	bool bEnableWarnAboutMaterial0Override;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Config, Category="GridSnapping")
	bool bAllowLevelEditorToDisableCellSnap;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Config, Category="GridSnapping")
	bool bRotateBuildingActorsAroundCell;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Config, Category="GridSnapping")
	bool bForceBuildingActorsTo90DegreeRotation;
#endif

};

