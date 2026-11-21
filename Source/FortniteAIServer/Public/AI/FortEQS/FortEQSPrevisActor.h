// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "EnvironmentQuery/EQSQueryResultSourceInterface.h"
#include "GameFramework/Actor.h"
#include "GameplayTagAssetInterface.h"
#include "GameplayTagContainer.h"
#include "FortEQSPrevisActor.generated.h"

class UEQSRenderingComponent;
class UEnvQuery;
class USceneComponent;

UCLASS()
class AFortEQSPrevisActor : public AActor, public IEQSQueryResultSourceInterface, public IGameplayTagAssetInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent, Category="EQS", meta=(CallInEditor="true"))
	void PrepForPrevis();

	UFUNCTION(BlueprintCallable, Category="EQS", meta=(CallInEditor="true"))
	void SetQueryTemplate(UEnvQuery* InPrevisQueryTemplate);

	virtual void GetOwnedGameplayTags(FGameplayTagContainer& TagContainer) const override;

protected:
	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<USceneComponent> SceneRoot;

#if WITH_EDITORONLY_DATA
	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UEQSRenderingComponent> QueryVisualizationComponent;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY()
	TObjectPtr<UEnvQuery> PrevisQueryTemplate;
#endif

	UPROPERTY(EditAnywhere, Category="EQSPrevisActor")
	FGameplayTagContainer GameplayTags;

};

