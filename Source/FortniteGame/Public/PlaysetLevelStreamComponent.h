// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameFramework/OnlineReplStructs.h"
#include "Items/FortPlaysetStreamingData.h"
#include "PlaysetLevelStreamComponent.generated.h"

class UFortPlaysetItemDefinition;
class ULevelStreaming;
class ULevelStreamingDynamic;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FClientAcknowledgedPlayetsetDataReceivedDelegate);

UCLASS(ClassGroup=("Custom"), meta=(BlueprintSpawnableComponent))
class FORTNITEGAME_API UPlaysetLevelStreamComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Playset Level Stream")
	void ClearPlayset();

	UFUNCTION(BlueprintPure, Category="Playspace")
	const UFortPlaysetItemDefinition* GetCurrentPlayset() const;

	UFUNCTION(BlueprintPure, Category="Playset Level Stream")
	bool IsLoading() const;

	UFUNCTION(BlueprintCallable, Category="Playset Level Stream")
	void SetPlayset(const UFortPlaysetItemDefinition* NewPlayset);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Playset Level Stream")
	float MaxStreamInDistance;

	UPROPERTY(EditAnywhere, Category="Playset Level Stream")
	uint8 bAutoLoadLevel : 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Playset Level Stream")
	uint8 bAllowUnload : 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Playset Level Stream")
	bool bWaitOnMessageBeforeLoading;

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Transient, Category="Playset")
	uint8 bPreviewPlaysetInEditor : 1;
#endif

private:
	UFUNCTION()
	void OnFinishedLoading();

	UFUNCTION()
	void OnFinishedUnloading();

	UFUNCTION()
	void OnRep_ClientPlaysetData();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, Category="Playset Level Stream", meta=(AllowPrivateAccess="TRUE"))
	TObjectPtr<UFortPlaysetItemDefinition> CurrentPlayset;

	UPROPERTY(ReplicatedUsing=OnRep_ClientPlaysetData)
	FFortPlaysetStreamingData ClientPlaysetData;

	UPROPERTY(EditAnywhere, Category="Playset Level Stream")
	bool bIgnorePlaysetVolumeLocationChecks;

	UPROPERTY()
	TArray<FUniqueNetIdRepl> PlayersWithValidPlaysetData;

	UPROPERTY()
	TObjectPtr<ULevelStreamingDynamic> StreamedLevel;

	UPROPERTY()
	FName ClientLoadedPackageName;

#if WITH_EDITORONLY_DATA
	UPROPERTY(Transient)
	TObjectPtr<ULevelStreaming> PreviewLevelStream;
#endif

};

