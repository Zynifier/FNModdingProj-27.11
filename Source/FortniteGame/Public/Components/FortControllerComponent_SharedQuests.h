// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ControllerComponent.h"
#include "GameFramework/OnlineReplStructs.h"
#include "FortControllerComponent_SharedQuests.generated.h"

UCLASS(Config=game, MinimalAPI, HideCategories=("Trigger", "PhysicsVolume"))
class UFortControllerComponent_SharedQuests : public UControllerComponent
{
	GENERATED_BODY()

public:
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnAssistPlayerCleaningUpSharedQuests, const FUniqueNetIdRepl&, PlayerId);

public:
	UFortControllerComponent_SharedQuests(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

public:
	UFUNCTION(BlueprintPure, Category="Quests")
	bool CanGrantSharedQuests() const;

private:
	UPROPERTY(Config)
	bool bBlockPartyAssist;

	UPROPERTY(Config)
	bool bUseSquadForPartyAssist;

};

