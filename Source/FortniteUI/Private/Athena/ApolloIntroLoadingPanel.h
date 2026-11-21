// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/AthenaLoadingScreenPreviewPanelBase.h"
#include "ApolloIntroLoadingPanel.generated.h"

class UFortPlaylistAthena;

UCLASS()
class UApolloIntroLoadingPanel : public UAthenaLoadingScreenPreviewPanelBase
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	TObjectPtr<UFortPlaylistAthena> ApolloIntroPlaylist;

};

