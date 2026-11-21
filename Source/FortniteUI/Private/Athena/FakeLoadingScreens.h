// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/AthenaLoadingScreenPreviewPanelBase.h"
#include "FakeLoadingScreens.generated.h"

class UFortPlaylistAthena;

UCLASS()
class UGuidedTutorialLoadingScreen : public UAthenaLoadingScreenPreviewPanelBase
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	TObjectPtr<UFortPlaylistAthena> GuidedTutorialPlaylist;

};

