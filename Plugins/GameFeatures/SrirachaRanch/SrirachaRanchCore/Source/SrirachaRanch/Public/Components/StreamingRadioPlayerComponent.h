// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameplayTagContainer.h"
#include "Athena/FortVehicleSeatInputHookProvider.h"
#include "Components/FortPawnComponent.h"
#include "EpicStreamMediaSource.h"
#include "Media/FortBaseStreamingVideo.h"
#include "ModuleBoundary/PrimitiveModularCrosstalkInterface.h"
#include "Types/SrirachaRanchTypes.h"
#include "StreamingRadioPlayerComponent.generated.h"

class AActor;
class AController;
class AFortAthenaVehicle;
class AFortPawn;
class AFortWeapon;
class IFortVehicleInterface;
class UFortBaseStreamingVideo;
class UFortStreamMediaSource;
class UMediaSoundComponent;
class UObject;
class URadioContentSourceItemDefinition;
class USoundMix;
class USoundSubmixBase;
class USrirachaRanchComponentTemplateWrapper;
class UStreamingRadioAudioShapeComponent;
class UStreamingRadioPlayerComponent;
enum class EBaseMediaTerminalErrorReason : uint8;
enum class EStreamingRadioSourceState : uint8;

UENUM(BlueprintType)
enum class EStreamingRadioSourceState : uint8
{
	None = 0,
	LoadingPlayer = 1,
	LoadedPlayer = 2,
	Playing = 3,
};

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnReplicatedStateChanged, EStreamingRadioSourceState, NewState);

USTRUCT(BlueprintType)
struct FAthenaRadioStation
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AthenaRadioStation")
	FText Title;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AthenaRadioStation")
	FString StationImage;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AthenaRadioStation")
	FString ResourceID;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AthenaRadioStation")
	TArray<FString> GameplayTagDenylist;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AthenaRadioStation")
	TArray<FString> GameplayTagAllowlist;

};

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FStreamedRadioEvent, UStreamingRadioPlayerComponent*, Component, FAthenaRadioStation, AffectedSource);

USTRUCT()
struct FSrirachaPerClassSpecialSeats
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="SrirachaPerClassSpecialSeats")
	TArray<int32> OutsideSeatIndices;

};

USTRUCT()
struct FStreamingRadioSourceData
{
	GENERATED_BODY()

public:
	UPROPERTY()
	EStreamingRadioSourceState State;

	UPROPERTY()
	int32 PlayingIndex;

	UPROPERTY()
	float FadeoutSeconds;

	UPROPERTY()
	FAthenaRadioStation SourceOverride;

};

UCLASS(HideCategories=("AttenuationDistance", "AttenuationSpatialization", "AttenuationAirAbsorption", "AttenuationListenerFocus", "AttenuationReverbSend", "AttenuationOcclusion", "AttenuationPriority", "AttenuationSubmixSend", "AttenuationPluginSettings"))
class USrirachaRanchComponentTemplateWrapper : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Instanced, Category="Radio|Config")
	TObjectPtr<UMediaSoundComponent> MediaSoundPlayerTemplate;

};

UCLASS(Config=Game, BlueprintType, Blueprintable, HideCategories=("Trigger", "PhysicsVolume"))
class SRIRACHARANCH_API UStreamingRadioPlayerComponent : public UFortPawnComponent, public IPrimitiveModularCrosstalkInterface, public IVehicleSeatInputHookProvider
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Radio")
	UFortBaseStreamingVideo* GetBaseStreamingVideo();

	UFUNCTION(BlueprintCallable, Category="Radio")
	FFortMediaInBandMetadata GetMediaMetadata();

	UFUNCTION(BlueprintPure, Category="Radio")
	FAthenaRadioStation GetOptionAt(int32 Idx) const;

	UFUNCTION(BlueprintPure)
	bool IsExternalSeat(int32 SeatIdx) const;

	UFUNCTION(BlueprintPure, Category="Radio")
	bool IsPlayingLiveFeed() const;

	UFUNCTION(BlueprintCallable, BlueprintCosmetic, Category="Radio")
	void PlayDefaultIndex();

	UFUNCTION(BlueprintCallable, BlueprintCosmetic, Category="Radio")
	void PlayNextIndex();

	UFUNCTION(BlueprintCallable, BlueprintCosmetic, Category="Radio")
	void PlayPrevIndex();

	UFUNCTION(Server, Reliable)
	void ServerPlayIndex(const int32 InIndex, const EStreamingRadioSourceState InState);

	UFUNCTION(Server, Reliable)
	void ServerSaveAutoStart(const bool bInAutoStart);

	UFUNCTION(Server, Reliable)
	void ServerSavedSource(const FAthenaRadioStation& InSource);

	UFUNCTION(Server, Reliable)
	void ServerSaveFadeOutTime(const float InFadeOutSeconds);

	UFUNCTION(Server, Reliable)
	void ServerSetDisabledForCurrentPlayerState(const bool bInDisableForCurrentPlayerState);

	UFUNCTION(Server, Reliable)
	void ServerStopRadio();

	UFUNCTION(BlueprintCallable, Category="Radio")
	void SetActivationRadius(float InRadius);

	UFUNCTION(BlueprintCallable, BlueprintCosmetic, Category="Radio")
	void StartRadio(int32 IdxToPlay, bool bFallbackOverride = false);

	UFUNCTION(BlueprintCallable, BlueprintCosmetic, Category="Radio")
	void StopRadio();

	UFUNCTION(BlueprintCallable, BlueprintCosmetic, Category="Radio")
	void StopRadioWithFadeout(int32 Milliseconds);

	UFUNCTION(BlueprintCallable)
	void ToggleRadioActive();

	UPROPERTY(BlueprintAssignable, Category="Radio")
	FStreamedRadioEvent OnSourceLoading;

	UPROPERTY(BlueprintAssignable, Category="Radio")
	FStreamedRadioEvent OnSourcePlayed;

	UPROPERTY(BlueprintAssignable, Category="Radio")
	FStreamedRadioEvent OnSourceStopped;

	UPROPERTY(BlueprintAssignable, Category="Radio")
	FStreamedRadioEvent OnSourceFailed;

	UPROPERTY(BlueprintAssignable, Category="Radio")
	FFortMediaMetadataEvent OnMetadataChanged;

	UPROPERTY(BlueprintAssignable, Category="Radio")
	FStreamedRadioEvent OnRadioExplicitStop;

protected:
	UFUNCTION()
	void HandleLicensedAudioTreatmentChanged(UCPTypes UcpType);

	UFUNCTION()
	bool IsRadioOn() const;

	UFUNCTION()
	void MediaClose();

	UFUNCTION()
	void MediaClosed();

	UFUNCTION()
	void MediaEnded();

	UFUNCTION()
	void MediaOnSuccess();

	UFUNCTION()
	void MediaResumed();

	UFUNCTION()
	void MediaTerminalError(EBaseMediaTerminalErrorReason Reason);

	UFUNCTION()
	void MetadataChanged(FFortMediaInBandMetadata Metadata);

	UFUNCTION()
	void NativeOnPawnEnterSeat(const TScriptInterface<IFortVehicleInterface>& Vehicle, AFortPawn* PlayerPawn, int32 SeatIndex);

	UFUNCTION()
	void NativeOnPawnEnterVehicle(const TScriptInterface<IFortVehicleInterface>& Vehicle, AFortPawn* PlayerPawn, int32 SeatIndex);

	UFUNCTION()
	void NativeOnPawnExitSeat(const TScriptInterface<IFortVehicleInterface>& Vehicle, AFortPawn* PlayerPawn, int32 SeatIndex);

	UFUNCTION()
	void NativeOnPawnExitVehicle(const TScriptInterface<IFortVehicleInterface>& Vehicle, AFortPawn* PlayerPawn, int32 SeatIndex);

	UFUNCTION()
	void NativeOnVehicleOwnerChanged(const TScriptInterface<IFortVehicleInterface>& Vehicle, const AActor* NewOwner, const AActor* PrevOwner);

	UFUNCTION()
	void OnOwnerDisabledChanged(bool bDisabled);

	UFUNCTION()
	void OnOwnerExploded();

	UFUNCTION()
	void OnOwnerOutOfFuel();

	UFUNCTION()
	void OnOwnerReFueled();

	UFUNCTION()
	void OnOwnerUnpowered();

	UFUNCTION()
	void OnOwningVehicleDied(AFortAthenaVehicle* DeadVehicle, const FGameplayTagContainer& InTags, AController* EventInstigator, AActor* DamageCauser);

	UFUNCTION(BlueprintImplementableEvent, Category="VehicleOccupancyEvents")
	void OnPawnEnterSeat(const TScriptInterface<IFortVehicleInterface>& Vehicle, AFortPawn* PlayerPawn, int32 SeatIndex);

	UFUNCTION(BlueprintImplementableEvent, Category="VehicleOccupancyEvents")
	void OnPawnEnterVehicle(const TScriptInterface<IFortVehicleInterface>& Vehicle, AFortPawn* PlayerPawn, int32 SeatIndex);

	UFUNCTION(BlueprintImplementableEvent, Category="VehicleOccupancyEvents")
	void OnPawnExitSeat(const TScriptInterface<IFortVehicleInterface>& Vehicle, AFortPawn* PlayerPawn, int32 SeatIndex);

	UFUNCTION(BlueprintImplementableEvent, Category="VehicleOccupancyEvents")
	void OnPawnExitVehicle(const TScriptInterface<IFortVehicleInterface>& Vehicle, AFortPawn* PlayerPawn, int32 SeatIndex);

	UFUNCTION()
	void OnPiPPlayerBlockedChanged(bool bPiPPlayerBlocking);

	UFUNCTION()
	void OnRep_RadioSourceData();

	UFUNCTION()
	void SetExteriorVolume(const TScriptInterface<IFortVehicleInterface>& Vehicle);

	UFUNCTION()
	void SetInteriorVolume(const TScriptInterface<IFortVehicleInterface>& Vehicle);

	UFUNCTION()
	void StopIfNoDriver(const TScriptInterface<IFortVehicleInterface>& Vehicle);

#if WITH_EDITORONLY_DATA
	UPROPERTY(VisibleAnywhere, Transient, NoClear, EditFixedSize, Category="StreamingRadioPlayerComponent")
	TMap<EPrimitiveCrosstalkFunctions, FPrimitiveCrosstalkNameArray> SupportedFunctions;
#endif

	UPROPERTY(EditDefaultsOnly, NoClear, EditFixedSize, Category="StreamingRadioPlayerComponent")
	TMap<FName, FSrirachaInputMappingData> InputMappingData;

	UPROPERTY(Config)
	float PercentAutostartRadio;

	UPROPERTY(Config)
	TArray<FName> DisabledVehicleList;

	UPROPERTY(Config)
	TMap<FName, float> ExteriorVolumeMultiplierMap;

	UPROPERTY(Config)
	TMap<FName, float> InteriorVolumeMultiplierMap;

	UPROPERTY(Config)
	bool bMinimalStateOnPlatform;

	UPROPERTY(Config)
	TArray<FString> DisabledStationList;

	UPROPERTY(Replicated)
	bool bAutostartOnEntry;

	UPROPERTY(Replicated)
	bool bDisabledForCurrentPlayerState;

	UPROPERTY(ReplicatedUsing=OnRep_RadioSourceData)
	FStreamingRadioSourceData ReplicatedRadioSourceData;

	UPROPERTY(BlueprintAssignable, Category="Radio")
	FOnReplicatedStateChanged OnReplicatedStateChangedDelegate;

	UPROPERTY(BlueprintReadOnly, Transient, Export, Category="Radio", meta=(EditInline="true"))
	TObjectPtr<UMediaSoundComponent> SoundComponent;

	UPROPERTY(BlueprintReadOnly, Transient, Export, Category="Radio", meta=(EditInline="true"))
	TObjectPtr<UStreamingRadioAudioShapeComponent> AudioShape;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Radio|Config")
	TObjectPtr<USrirachaRanchComponentTemplateWrapper> SoundCompTemplateSource;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="Radio")
	FAthenaRadioStation LastSource;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Radio|Config")
	TArray<TObjectPtr<URadioContentSourceItemDefinition>> Sources;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Radio|Config")
	FAthenaRadioStation FallbackSource;

	UPROPERTY(EditAnywhere, Category="Radio|Config")
	TMap<FGameplayTag, FSrirachaPerClassSpecialSeats> SpecialSeatList;

	UPROPERTY(Transient)
	TObjectPtr<UFortBaseStreamingVideo> BasePlayerInstance;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Radio|Config")
	TObjectPtr<USoundSubmixBase> DefaultSoundSubmix;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Radio|Config")
	TObjectPtr<USoundSubmixBase> LicensedSoundSubmix;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Radio|Config")
	ERadioSource CurrentMode;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Radio|Config")
	int32 MaximumRetries;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Config, Category="Radio|Config")
	int32 FadeoutWhenUnpoweredInMS;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Radio|Config")
	int32 FadeoutWhenOwnerBeingDestroyedInMS;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Radio|Config")
	int32 MaxFadeoutTimeMS;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Config, Replicated, Category="Radio|Config")
	int32 DefaultPlayingIndex;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Radio|Config")
	TObjectPtr<USoundMix> SoundMixInside;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Radio|Config")
	TObjectPtr<USoundMix> SoundMixOutside;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Radio|Config")
	float ActivationRadius;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Radio|Attachment")
	FName ComponentToAttachTo;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Radio|Attachment")
	FName ComponentSocketAttachTo;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="RadioResource")
	TObjectPtr<UFortStreamMediaSource> MediaSource;

	UPROPERTY()
	TArray<FAthenaRadioStation> RadioStationList;

	UPROPERTY(Transient)
	TObjectPtr<UObject> DelegateContextObject;

private:
	UFUNCTION()
	void SoundMixUpdateTargetingState(bool bNewIsTargeting);

	UFUNCTION()
	void SoundMixUpdateWeaponState(AFortWeapon* NewWeapon, AFortWeapon* PrevWeapon);

	UPROPERTY(Replicated)
	float MediaStartTimeFromInit;

};

