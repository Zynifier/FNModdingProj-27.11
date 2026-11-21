// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "FortAsyncAction_EnsureClientQuestLogin.generated.h"

class UFortAsyncAction_EnsureClientQuestLogin;
class UFortQuestManager;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FFortEnsureClientQuestLoginDelegate);

UCLASS()
class UFortAsyncAction_EnsureClientQuestLogin : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Quests", meta=(BlueprintInternalUseOnly="true"))
	static UFortAsyncAction_EnsureClientQuestLogin* SendEnsureClientQuestLogin(UFortQuestManager* QuestManager);

	UPROPERTY(BlueprintAssignable)
	FFortEnsureClientQuestLoginDelegate OnSuccess;

	UPROPERTY(BlueprintAssignable)
	FFortEnsureClientQuestLoginDelegate OnFailure;

private:
	UPROPERTY(Transient)
	TObjectPtr<UFortQuestManager> QuestManager;

};

