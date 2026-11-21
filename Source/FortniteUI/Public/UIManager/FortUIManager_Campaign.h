// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UIManager/FortUIManager.h"
#include "FortUIManager_Campaign.generated.h"

class IFortUIManagerInterface;
class UFortLocalPlayer;

USTRUCT()
struct FFortUIManager_Campaign_Player
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TObjectPtr<UFortLocalPlayer> Player;

	UPROPERTY()
	TScriptInterface<IFortUIManagerInterface> Manager;

};

UCLASS()
class FORTNITEUI_API UFortUIManager_Campaign : public UFortUIManager
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient)
	TArray<FFortUIManager_Campaign_Player> InterfaceStack;

};

