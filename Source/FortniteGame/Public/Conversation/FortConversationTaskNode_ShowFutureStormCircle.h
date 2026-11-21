// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Conversation/FortConversationTaskNode_Service.h"
#include "FortConversationTaskNode_ShowFutureStormCircle.generated.h"

class UFortGameplayAbility;

UENUM(BlueprintType)
enum class EPreventUseStormCircleServiceReason : uint8
{
	CannotAfford = 0,
	AlreadyActive = 1,
	StormLocationsAlreadyRevealed = 2,
	None = 3 UMETA(Hidden),
};

UCLASS(Abstract, meta=(DisplayName="Show Future Storm Circle"))
class UFortConversationTaskNode_ShowFutureStormCircle : public UFortConversationTaskNode_Service
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, AdvancedDisplay, Category="Effects")
	TSubclassOf<UFortGameplayAbility> GrantedAbility;

	UPROPERTY(EditDefaultsOnly, AdvancedDisplay, Category="Effects")
	int32 Level;

};

