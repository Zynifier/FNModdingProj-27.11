// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "DataProviders/AIDataProvider.h"
#include "EnvironmentQuery/EnvQueryGenerator.h"
#include "FortQueryGenerator_PerceivedActors.generated.h"

USTRUCT()
struct FFortQueryGenerator_PerceivedActors_Settings
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Generator")
	bool bIgnoreDBNOPawns;

	UPROPERTY(EditAnywhere, Category="Generator")
	bool bIgnoreSleepingAIs;

	UPROPERTY(EditAnywhere, Category="Generator")
	FAIDataProviderFloatValue MaxTimeSincePerceived;

};

UCLASS(MinimalAPI, meta=(DisplayName="Goal: Perceived Actor"))
class UFortQueryGenerator_PerceivedActors : public UEnvQueryGenerator
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category="Generator")
	bool bGenerateHostileActorGoal;

	UPROPERTY(EditAnywhere, Category="Generator", meta=(EditCondition="bGenerateHostileActorGoal", EditConditionHides))
	FFortQueryGenerator_PerceivedActors_Settings HostileActorSettings;

	UPROPERTY(EditAnywhere, Category="Generator")
	bool bGenerateNeutralActorGoal;

	UPROPERTY(EditAnywhere, Category="Generator", meta=(EditCondition="bGenerateNeutralActorGoal", EditConditionHides))
	FFortQueryGenerator_PerceivedActors_Settings NeutralActorSettings;

	UPROPERTY(EditAnywhere, Category="Generator")
	bool bGenerateFriendlyActorGoal;

	UPROPERTY(EditAnywhere, Category="Generator", meta=(EditCondition="bGenerateFriendlyActorGoal", EditConditionHides))
	FFortQueryGenerator_PerceivedActors_Settings FriendlyActorSettings;

};

