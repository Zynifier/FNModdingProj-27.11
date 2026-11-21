// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Math/MathFwd.h"
#include "FortPoiSwapManager.generated.h"

class AFortPoiSwapPlayspace;
class AFortPoiVolume;
class UFortMcpProfileCreative;
enum class EFortPoiSwapUserContentState : uint8;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnPlayspaceContentUpdated, AFortPoiSwapPlayspace*, PoiSwapPlayspace);

UCLASS(MinimalAPI, BlueprintType, Blueprintable)
class UFortPoiSwapManager : public UActorComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, BlueprintAuthorityOnly)
	AFortPoiSwapPlayspace* GetPlayspaceForPoi(const AFortPoiVolume* PoiVolume) const;

	UFUNCTION(BlueprintPure, BlueprintAuthorityOnly)
	FString GetPoiSubPlotLinkCode(const AFortPoiVolume* PoiVolume) const;

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void SetPoiSubPlot(const AFortPoiVolume* PoiVolume, const FString& SubPlotName, const FString& SubPlotLinkCode);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void SwapPoi(const AFortPoiVolume* PoiToSwap);

	UPROPERTY(BlueprintAssignable)
	FOnPlayspaceContentUpdated OnPlayspaceLoadedContentDelegate;

	UPROPERTY(BlueprintAssignable)
	FOnPlayspaceContentUpdated OnPlayspaceUnloadedContentDelegate;

	UPROPERTY(BlueprintAssignable)
	FOnPlayspaceContentUpdated OnPrePlayspaceContentUnloadDelegate;

protected:
	UFUNCTION()
	void OnPlayspaceContentLoadingStateChanged(AFortPoiSwapPlayspace* PoiSwapPlayspace, const EFortPoiSwapUserContentState& ContentLoadingState);

	UFUNCTION()
	void OnPrePlayspaceContentUnload(AFortPoiSwapPlayspace* PoiSwapPlayspace);

	UPROPERTY(Transient)
	TWeakObjectPtr<UFortMcpProfileCreative> CachedIslandOwnerProfile;

	UPROPERTY(EditDefaultsOnly, Category="FortPoiSwapManager")
	FVector PoiPlotLocationOffset;

};

