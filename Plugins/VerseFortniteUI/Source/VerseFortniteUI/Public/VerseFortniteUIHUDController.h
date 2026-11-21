// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/Modifiers/FortAthenaMutator_HUDElementVisibility.h"
#include "Playspace/VerseFortnitePlayspace.h"
#include "VerseFortniteUIHUDController.generated.h"

UCLASS(Abstract)
class UVerseFortnitePlayspaceHUDController : public UVerseFortnitePlayspaceExtensionBase
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient)
	FHUDElementVisibilityRepData VisibilityData;

};

