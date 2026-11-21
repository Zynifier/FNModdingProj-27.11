// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Conversation/FortConversationTaskNode_Service.h"
#include "FortConversationTaskNode_ApplyAbility.generated.h"

class UFortGameplayAbility;

UENUM(BlueprintType)
enum class EPreventAbilityUseReason : uint8
{
	CannotAfford = 0,
	AlreadyActive = 1,
	AbilityActivationBlocked = 2,
	None = 3 UMETA(Hidden),
	Count = 4 UMETA(Hidden),
};

UCLASS(Abstract)
class UFortConversationTaskNode_ApplyAbility : public UFortConversationTaskNode_Service
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, AdvancedDisplay, Category="Effects")
	TSubclassOf<UFortGameplayAbility> GrantedAbility;

	UPROPERTY(EditDefaultsOnly, AdvancedDisplay, Category="Effects")
	int32 Level;

	UPROPERTY(EditDefaultsOnly, AdvancedDisplay, Category="Effects")
	bool bPreventUseIfAbilityAlreadyActive;

	UPROPERTY(EditDefaultsOnly, AdvancedDisplay, Category="Effects", meta=(EditCondition="bPreventUseIfAbilityAlreadyActive"))
	FGameplayTagContainer ActiveAbilityGameplayTags;

	UPROPERTY(EditDefaultsOnly, AdvancedDisplay, Category="Effects")
	bool bActivateImmediatelyOnGranting;

	UPROPERTY(EditDefaultsOnly, AdvancedDisplay, Category="Events")
	FGameplayTag ServiceGameplayTag;

	UPROPERTY(EditDefaultsOnly, AdvancedDisplay, Category="Events")
	FString AnalyticsEventName;

	UPROPERTY(EditDefaultsOnly, AdvancedDisplay, Category="Requirements")
	FName PricingKey;

};

