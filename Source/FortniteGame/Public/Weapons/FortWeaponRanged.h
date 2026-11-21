// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Chaos/ChaosEngineInterface.h"
#include "Engine/HitResult.h"
#include "Engine/Scene.h"
#include "GameplayEffectTypes.h"
#include "Math/Color.h"
#include "Math/MathFwd.h"
#include "Abilities/FortAbilityTargetingSourceEnum.h"
#include "FortEffectDistanceQuality.h"
#include "Weapons/Data/FortWeaponRangedItemDefinition.h"
#include "Weapons/FortWeapon.h"
#include "Weapons/Projectiles/FortLightweightProjectileManager.h"
#include "FortWeaponRanged.generated.h"

class AActor;
class AFortPawn;
class AFortProjectileBase;
class AFortTracerBase;
class IFortAthenaAILODSettings;
class UAnimMontage;
class UAnimationAsset;
class UFXSystemComponent;
class UMaterialInterface;
class UNiagaraComponent;
class UNiagaraSystem;
class UParticleSystem;
class UParticleSystemComponent;
class USkeletalMesh;
class USoundBase;
class UStaticMeshComponent;
class UTexture2D;
enum class EFortWeaponOverheatState : uint8;

UENUM(BlueprintType)
enum class EFortWeaponOverheatState : uint8
{
	None = 0,
	Heating = 1,
	Cooling = 2,
	Overheated = 3,
};

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_FourParams(FOnOverheatValueChanged, float, CurrentValue, float, MaxValue, EFortWeaponOverheatState, State, bool, bIsInCooldown);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnProjectileSpawned);

USTRUCT(BlueprintType)
struct FFortBulletPatternEntry
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortBulletPatternEntry")
	FFortBulletPatternEntryData EntryData;

};

USTRUCT()
struct FRotationDebugInfo
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FRotator PreviousRotation;

	UPROPERTY()
	FRotator DeltaRotation;

	UPROPERTY()
	FRotator InputDeltaRot;

	UPROPERTY()
	FRotator RotationToPreserveLocation;

	UPROPERTY()
	FRotator RecoilDeltaRot;

	UPROPERTY()
	FRotator MaxAimAdjustThisFrame;

	UPROPERTY()
	float WeaponEquipDeltaTime;

	UPROPERTY()
	float AimAdjustRemainingTime;

	UPROPERTY()
	float TargetDistance;

	UPROPERTY()
	uint8 CameraStackNumber;

	UPROPERTY()
	uint8 bJustStartedTargetingTransition : 1;

	UPROPERTY()
	uint8 bUpdatingForADSTransition : 1;

	UPROPERTY()
	uint8 bIsTargeting : 1;

	UPROPERTY()
	uint8 bMuzzleIsBlocked : 1;

	UPROPERTY()
	uint8 bShouldAdjustCamera : 1;

	UPROPERTY()
	uint8 bHadInputFromFrameCounter : 1;

	UPROPERTY()
	uint8 bHadInputRotation : 1;

};

USTRUCT()
struct FWeaponCueReplicationStruct
{
	GENERATED_BODY()

public:
	UPROPERTY()
	uint32 RepCounter;

	UPROPERTY()
	TEnumAsByte<EGameplayCueEvent::Type> CueEventType;

	UPROPERTY()
	FGameplayCueParameters Parameters;

};

UCLASS(Config=Game, MinimalAPI, HideCategories=("Actor", "Input", "Components|Clothing", "Components|Base", "Components|PhysicsVolume", "Components|Activation", "Collision", "Replication", "Rendering", "Tags"))
class AFortWeaponRanged : public AFortWeapon
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent, Category="Targeting")
	void AbortScopeFX();

	UFUNCTION(BlueprintNativeEvent)
	bool BP_AllowRaiseWeaponForDeferredFireInput() const;

	UFUNCTION(BlueprintPure, Category="Overheat")
	bool DoesWeaponOverheat() const;

	UFUNCTION(BlueprintCallable, Category="Reticle")
	void EnableAltCenterReticle(bool bNewEnabled);

	UFUNCTION(BlueprintCallable, Category="Reticle")
	void EnableAltOuterReticle(bool bNewEnabled);

	UFUNCTION(BlueprintCallable, Category="Reticle")
	void EnableCornersReticle(bool bNewEnabled);

	UFUNCTION(BlueprintImplementableEvent, Category="Targeting")
	void ForceScopeFX();

	UFUNCTION(BlueprintPure, Category="Weapon")
	float GetADSTransitionInTime() const;

	UFUNCTION(BlueprintPure, Category="Weapon")
	float GetADSTransitionOutTime() const;

	UFUNCTION(BlueprintPure, Category="Reticle")
	float GetCalculatedReticleSpread() const;

	UFUNCTION(BlueprintPure, Category="Overheat")
	float GetCurrentOverheatValue() const;

	UFUNCTION(BlueprintPure, Category="Reticle")
	float GetCurrentReticleSpreadMultiplier() const;

	UFUNCTION(BlueprintPure, Category="CharacterAnimation")
	UAnimMontage* GetFireDownsightsAnimation() const;

	UFUNCTION(BlueprintPure, Category="Reticle")
	float GetMaxAdditionalPatternSpreadDegrees() const;

	UFUNCTION(BlueprintPure, Category="Overheat")
	float GetOverheatingMaxValue() const;

	UFUNCTION(BlueprintPure, Category="Overheat")
	EFortWeaponOverheatState GetOverheatState() const;

	UFUNCTION(BlueprintImplementableEvent, Category="FortWeapon")
	void GetScopeParameters(UStaticMeshComponent*& ScopeComponent, FVector2D& DepthOfFieldVignetteRange, FVector& WeaponSightsOffset);

	UFUNCTION(BlueprintPure, Category="Scope")
	const TArray<FWeightedBlendable>& GetScopePostProcessMaterial() const;

	UFUNCTION(BlueprintPure, Category="Effects")
	void GetUniqueMuzzleSocketNames(TArray<FName>& Names) const;

	UFUNCTION(BlueprintPure, Category="WeaponAnimation")
	UAnimMontage* GetWeaponFireDownsightsMontage() const;

	UFUNCTION(BlueprintPure, Category="Scope")
	bool HasPostProcessMaterialFromOptic() const;

	UFUNCTION(BlueprintCallable, Category="Reticle")
	void InitUpdateOverheatingState();

	UFUNCTION(BlueprintPure, Category="Overheat")
	bool IsOverheated() const;

	UFUNCTION(BlueprintPure, Category="Weapon")
	bool IsUsingFirstPersonCamera() const;

	UFUNCTION(BlueprintPure, Category="Weapon")
	bool IsUsingScope() const;

	UFUNCTION(BlueprintPure, Category="Weapon")
	bool IsUsingScopeOrFirstPersonCamera() const;

	UFUNCTION(NetMulticast, Unreliable)
	void MulticastLWProjectile_EndActiveAbility(const float FiringTimestamp);

	UFUNCTION(NetMulticast, Reliable)
	void MulticastProjectileRequestReliable(const FFortLightweightProjectileRequest& ProjectileRequest);

	UFUNCTION(NetMulticast, Unreliable)
	void MulticastProjectileRequestUnreliable(const FFortLightweightProjectileRequest& ProjectileRequest);

	UFUNCTION(NetMulticast, Unreliable)
	void MulticastStopProjectileRequestUnreliable(AActor* Requester);

	UFUNCTION(NetMulticast, Unreliable)
	void NetMulti_SimulateFireFX();

	UFUNCTION(Server, Unreliable)
	void ServerLWProjectile_EndActiveAbility(const float FiringTimestamp);

	UFUNCTION(Server, Reliable)
	void ServerNotifyPawnHit(FHitResult Hit, const FVector& ProjectileOriginPosition, const TArray<uint8>& Context);

	UFUNCTION(Category="FortWeapon|Scope")
	void SetFirstPersonTargeting(const bool bNewUseFirstPersonTargeting);

	UFUNCTION(BlueprintCallable, Category="FortWeapon|Effects")
	void SetUseBeamParticles(bool bNewUseBeamParticles);

	UFUNCTION(BlueprintCallable, Category="FortWeapon|Effects")
	void SetUseImpactDecals(bool bNewUseImpactDecals);

	UFUNCTION(BlueprintCallable, Category="FortWeapon|Effects")
	void SetUseShellsParticles(bool bNewUseShellsParticles);

	UFUNCTION(BlueprintCallable, Category="FortWeapon|Effects")
	void SetUseTracers(bool bNewUseTracers);

	UFUNCTION(BlueprintPure, Category="FortWeapon")
	virtual bool ShouldDisplayAmmoCounter() const;

	UFUNCTION(BlueprintPure, Category="FortWeapon")
	bool ShouldDisplayAmmoCounterDuringSecondaryFire() const;

	UFUNCTION(BlueprintPure, Category="FortWeapon")
	virtual bool ShouldDisplayReticleAmmoCounter() const;

	UFUNCTION(BlueprintCallable, Category="Overheat")
	bool ShouldDisplayReticleOverheatIndicator();

	UFUNCTION(BlueprintPure, Category="FortWeapon")
	bool ShouldHideReticleAmmoCounterWhileTargeting() const;

	UFUNCTION(BlueprintPure, Category="Effects")
	virtual bool ShouldPlayPersistentFireFX() const;

	UFUNCTION(BlueprintPure, Category="Effects")
	bool ShouldPlayReloadFX() const;

	UFUNCTION(BlueprintPure, Category="Effects")
	bool ShouldPlayShellFX() const;

	UFUNCTION(BlueprintPure, Category="Targeting")
	bool UseFirstPersonTargeting() const;

	UFUNCTION(BlueprintPure, Category="Scope")
	bool UseScopeTargeting() const;

	UPROPERTY(BlueprintAssignable, Category="Overheating")
	FOnOverheatValueChanged OnOverheatValueChanged;

	UPROPERTY(EditDefaultsOnly, Category="Targeting")
	bool bUseTargetingBasedLOD;

protected:
	UFUNCTION(BlueprintCallable)
	void ActivateMuzzleFlashFXNative(const bool bPersistantFire, const bool bMuzzleUsesNiagara, const TSoftObjectPtr<UNiagaraSystem>& MuzzleNiagaraAsset, const TArray<UParticleSystemComponent*>& LegacyMuzzleFXComponents, const float MuzzleChanceOfLargeFlash, const float MuzzleFlashLargeMinScale, const float MuzzleFlashLargeMaxScale, const float MuzzleFlashSmallMinScale, const float MuzzleFlashSmallMaxScale);

	UFUNCTION(BlueprintCallable)
	void ActivateShellsFXNative(UNiagaraSystem* ShellBurstFX, UNiagaraSystem* ShellLoopingFX, const FName ShellSocketName, const FName RotationRateName, const FVector& RotationRate, const FName VelocityName, const FVector& Velocity, const FName GravityName, const FVector& Gravity, const FName SizeName, const FVector& Size, const FName ParentVelocityName, const FVector& ParentVelocity, const FName RadiusName, const float Radius, const FName HeightName, const float Height, const FName ColorName, const FLinearColor& ShellColor, const FName ShellTypeName, const int32 ShellTypeInt, const float CullDistance, const bool bUseShellsOnReload, const FName SpawnProbabilityName, const float SpawnRateScale);

	UFUNCTION(BlueprintCallable, Category="FortWeapon")
	void ClearHomingTarget();

	UFUNCTION(Client, Reliable)
	void ClientFixOverheatState(EFortWeaponOverheatState NewOverheatState);

	UFUNCTION(Client, Reliable)
	void ClientFixupOverheatValue(const float InOverheatValue);

	UFUNCTION(BlueprintCallable, Category="Effects")
	void DeactivateBeamFX();

	UFUNCTION(BlueprintCallable)
	void DeactivateMuzzleFlashFXNative(const TArray<UParticleSystemComponent*>& LegacyMuzzleFXComponents);

	UFUNCTION(BlueprintCallable)
	void DeactivateShellsFXNative(const FName SpawnProbabilityName);

	UFUNCTION(BlueprintPure)
	UNiagaraComponent* GetBeamNiagaraComponent() const;

	UFUNCTION(BlueprintPure, Category="Effects")
	UNiagaraSystem* GetBeamNiagaraSystem() const;

	UFUNCTION(BlueprintPure, Category="Effects")
	UParticleSystem* GetBeamParticleSystem() const;

	UFUNCTION(BlueprintPure)
	UParticleSystemComponent* GetBeamPSC() const;

	UFUNCTION(BlueprintPure, Category="CharacterAnimation")
	UAnimMontage* GetFireAnimation() const;

	UFUNCTION(BlueprintPure)
	int32 GetShellReloadCounter() const;

	UFUNCTION(BlueprintPure, Category="Effects")
	TSubclassOf<AFortTracerBase> GetTracerTemplate() const;

	UFUNCTION(BlueprintPure, Category="Effects")
	bool GetUseBeamParticles() const;

	UFUNCTION(BlueprintPure, Category="WeaponAnimation")
	UAnimMontage* GetWeaponFireMontage() const;

	UFUNCTION(BlueprintCallable, Category="Effects")
	void InitializeBeamFX(UFXSystemComponent* InBeamPSC);

	UFUNCTION(BlueprintNativeEvent, Category="FortWeapon")
	bool IsCachedIsProjectileWeapon() const;

	UFUNCTION(BlueprintImplementableEvent, Category="Overheating")
	void OnFinishedCooling();

	UFUNCTION(BlueprintImplementableEvent, Category="Overheating")
	void OnLocalFailedToFireWhenOverheated();

	UFUNCTION()
	void OnRep_OverheatState(EFortWeaponOverheatState PreviousOverheatState);

	UFUNCTION()
	void OnRep_ReplayActivationCue();

	UFUNCTION()
	void OnRep_ReplayImpactCue();

	UFUNCTION(BlueprintImplementableEvent, Category="FortWeapon")
	void OnSpawnProjectile(AFortProjectileBase* SpawnProjectile);

	UFUNCTION(BlueprintImplementableEvent, Category="Overheating")
	void OnStartCooling();

	UFUNCTION(BlueprintImplementableEvent, Category="Overheating")
	void OnStartHeating();

	UFUNCTION(BlueprintImplementableEvent, Category="Overheating")
	void OnStartOverheated();

	UFUNCTION(BlueprintCallable)
	void ReleaseShellsFXNative();

	UFUNCTION(Server, Unreliable)
	void ServerLWProjectile_SetDamageStartAndDirection(const FVector& InDamageStart, const FVector& InDamageDirection);

	UFUNCTION(Server, Reliable)
	void ServerSendRotationDebugInfo(const FRotationDebugInfo& DebugInfo);

	UFUNCTION(Server, Reliable)
	void ServerSetMuzzleTraceNearWall(bool bIsNearWall);

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerStopProjectileRequest();

	UFUNCTION(BlueprintCallable, Category="Effects")
	UNiagaraSystem* SetBeamNiagaraSystem(UNiagaraSystem* InputBeamNiagaraSystem);

	UFUNCTION(BlueprintCallable, Category="Effects")
	UParticleSystem* SetBeamParticleSystem(UParticleSystem* InputBeamParticleSystem);

	UFUNCTION(BlueprintCallable, Category="Decals")
	void SetDecalColorEnd(FLinearColor InputDecalColorEnd);

	UFUNCTION(BlueprintCallable, Category="Decals")
	void SetDecalColorStart(FLinearColor InputDecalColorStart);

	UFUNCTION(BlueprintCallable, Category="FortWeapon")
	void SetHomingTarget(AFortPawn* PlayerPawn);

	UFUNCTION(BlueprintCallable)
	void SetShellReloadCounter(int32 InputShellReloadCounter);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="FortWeapon")
	void SetUseOverrideBaseSpread(bool bUseOverride);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="FortWeapon")
	void SetUseOverrideSpreadDownsightsMultiplier(bool bUseOverride);

	UFUNCTION(BlueprintCallable, Category="Effects")
	bool ShouldSpawnBulletShellFX();

	UFUNCTION()
	void TempHack_PlayOverheatedAnimation();

	UFUNCTION()
	void VehicleSeatScopeFxHide(int32 SeatIndex);

	UFUNCTION()
	void VehicleSeatScopeFxShow();

	UPROPERTY(BlueprintAssignable)
	FOnProjectileSpawned OnProjectileSpawned;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_ReplayActivationCue)
	FWeaponCueReplicationStruct ReplayActivationCue;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_ReplayImpactCue)
	FWeaponCueReplicationStruct ReplayImpactCue;

	UPROPERTY(EditAnywhere, Category="Effects")
	TSubclassOf<AFortTracerBase> TracerTemplate;

	UPROPERTY(Config)
	bool bAllowAutomaticWeaponCatchup;

	UPROPERTY(Transient)
	int32 CurrentNumBullets;

	UPROPERTY(EditDefaultsOnly, Category="Scope")
	FVector ScopeTargetingMuzzleOffset;

	UPROPERTY(Transient)
	FVector CurrentMuzzleBlockedLocation;

	UPROPERTY(Transient)
	EFortAbilityTargetingSource CurrentDamageStart;

	UPROPERTY(EditDefaultsOnly, Category="Camera")
	FRotator MaxTargetingAimAdjustment;

	UPROPERTY(EditDefaultsOnly, Category="FortWeapon")
	uint8 bShouldDisplayAmmoCounter : 1;

	UPROPERTY(EditDefaultsOnly, Category="FortWeapon", meta=(EditCondition="bShouldDisplayAmmoCounter"))
	uint8 bShouldDisplayReticleAmmoCounter : 1;

	UPROPERTY(EditDefaultsOnly, Category="FortWeapon", meta=(EditCondition="bShouldDisplayReticleAmmoCounter"))
	uint8 bHideAmmoCounterDuringTargeting : 1;

	UPROPERTY(EditDefaultsOnly, Category="FortWeapon")
	uint8 bShouldDisplayAmmoCounterDuringSecondaryFire : 1;

	UPROPERTY(EditDefaultsOnly, Category="FortWeapon")
	uint8 bShouldHideReserveAmmo : 1;

	UPROPERTY(EditDefaultsOnly, Category="FortWeapon")
	uint8 bShouldAimFromMuzzleAtCloseRange : 1;

	UPROPERTY(EditDefaultsOnly, Category="FortWeapon")
	uint8 bAlwaysAimFromMuzzle : 1;

	UPROPERTY(EditDefaultsOnly, Category="Camera")
	uint8 bMaintainAimLocationDuringTargeting : 1;

	UPROPERTY(EditDefaultsOnly, Category="Scope")
	uint8 bUseScopeTargeting : 1;

	UPROPERTY(EditDefaultsOnly, Category="Targeting")
	uint8 bUseFirstPersonTargeting : 1;

	UPROPERTY(EditAnywhere, Category="Effects")
	uint8 bPersistentFireFX : 1;

	UPROPERTY(EditDefaultsOnly, Category="Effects")
	uint8 bUseBeamParticles : 1;

	UPROPERTY(EditDefaultsOnly, Category="Burst")
	uint8 bActivateRangeAbilityPerBurstShot : 1;

	UPROPERTY(EditDefaultsOnly, Category="Effects")
	uint8 bUseImpactFXForProjectiles : 1;

	UPROPERTY(EditDefaultsOnly, Category="Effects")
	uint8 bUseImpactFXForProjectileOverlaps : 1;

	UPROPERTY(EditDefaultsOnly, Category="Decals")
	uint8 bUseImpactDecals : 1;

	UPROPERTY(EditDefaultsOnly, Category="Effects")
	uint8 bUsePersistentBeam : 1;

	UPROPERTY(EditDefaultsOnly, Category="Effects")
	uint8 bUseShellsParticles : 1;

	UPROPERTY(EditDefaultsOnly, Category="Effects")
	uint8 bUseTracers : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Replicated, Category="Animation")
	uint8 bIsMuzzleTraceNearWall : 1;

	UPROPERTY(EditDefaultsOnly, Category="FortWeapon", meta=(ClampMax="180.0", ClampMin="0.0"))
	float MaxMuzzleAimCameraAimHeadingAngleDifferenceDegrees;

	UPROPERTY(EditDefaultsOnly, Category="FortWeapon", meta=(ClampMax="180.0", ClampMin="-180.0"))
	float AimPitchMin;

	UPROPERTY(EditDefaultsOnly, Category="FortWeapon", meta=(ClampMax="180.0", ClampMin="-180.0"))
	float AimPitchMax;

	UPROPERTY(EditDefaultsOnly, Category="FortWeapon")
	float MuzzleTraceNearWallThreshold;

	UPROPERTY(EditDefaultsOnly, Category="Effects Quality", meta=(EditCondition="bUseBeamParticles"))
	FFortEffectDistanceQuality BeamSignificance;

	UPROPERTY(EditDefaultsOnly, Category="Effects Quality")
	FFortEffectDistanceQuality ImpactSignificance;

	UPROPERTY(EditDefaultsOnly, Category="Effects Quality", meta=(EditCondition="bUseImpactDecals"))
	FFortEffectDistanceQuality DecalSignificance;

	UPROPERTY(EditDefaultsOnly, Category="Effects Quality")
	float ScopeImpactEffectDistanceOffset;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFXSystemComponent> MuzzlePSC;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFXSystemComponent> ShellPSC;

	UPROPERTY(EditDefaultsOnly, Category="Effects")
	TObjectPtr<UParticleSystem> BeamParticleSystem;

	UPROPERTY(EditDefaultsOnly, Category="Effects")
	TSoftObjectPtr<UNiagaraSystem> BeamNiagaraSystemAsset;

	UPROPERTY(EditDefaultsOnly, Category="Effects")
	FName BeamSourceSocketName;

	UPROPERTY(EditDefaultsOnly, Category="FortWeapon")
	TObjectPtr<USkeletalMesh> FortSpawnPropOverride;

	UPROPERTY(EditDefaultsOnly, Category="FortWeapon")
	TObjectPtr<UAnimationAsset> FortSpawnPropAnimOverride;

	UPROPERTY(EditDefaultsOnly, Category="Decals")
	FVector DecalSizeMin;

	UPROPERTY(EditDefaultsOnly, Category="Decals")
	FVector DecalSizeMax;

	UPROPERTY(EditDefaultsOnly, Category="Decals")
	float DecalLifespanMin;

	UPROPERTY(EditDefaultsOnly, Category="Decals")
	float DecalLifespanMax;

	UPROPERTY(EditDefaultsOnly, Category="Decals")
	FLinearColor DecalColorStart;

	UPROPERTY(EditDefaultsOnly, Category="Decals")
	FLinearColor DecalColorEnd;

	UPROPERTY(EditDefaultsOnly, Category="Decals")
	TObjectPtr<UMaterialInterface> DecalMaterial;

	UPROPERTY(EditDefaultsOnly, Category="Decals")
	TObjectPtr<UTexture2D> DecalTexture;

	UPROPERTY(EditDefaultsOnly, Category="Decals")
	TArray<TEnumAsByte<EPhysicalSurface>> SurfaceAcceptingDecals;

	UPROPERTY(Transient)
	int32 ShellReloadCounter;

	UPROPERTY(Transient)
	FRotator TargetingRotAdjustmentTotal;

	UPROPERTY(Transient)
	float LastTargetingRotAdjustmentWeight;

	UPROPERTY(EditDefaultsOnly, Category="Camera")
	FRotator MaxTargetingAimAdjustPerSecond;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Scope")
	bool ScopePostProcessEnabled;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Scope")
	float ScopePostProcessBlendWeight;

	UPROPERTY(EditAnywhere, Category="Scope")
	TArray<FWeightedBlendable> ScopePostProcessMaterial;

	UPROPERTY(EditAnywhere, Category="Scope")
	TArray<FWeightedBlendable> ScopePostProcessMaterialFromOptic;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortWeapon")
	TArray<FFortBulletPatternEntry> BulletPattern;

	UPROPERTY(EditDefaultsOnly, Category="Audio")
	TObjectPtr<USoundBase> EnemyWarningWeaponImpactSFX;

	UPROPERTY(EditAnywhere, Category="CharacterAnimation")
	TObjectPtr<UAnimMontage> FireAnimation;

	UPROPERTY(EditAnywhere, Category="CharacterAnimation")
	TObjectPtr<UAnimMontage> FireDownsightsAnimation;

	UPROPERTY(EditAnywhere, Category="CharacterAnimation")
	TObjectPtr<UAnimMontage> FireFromCrouchWalkAnimation;

	UPROPERTY(EditAnywhere, Category="CharacterAnimation")
	TObjectPtr<UAnimMontage> CockingAnimation;

	UPROPERTY(EditAnywhere, Category="WeaponAnimation")
	TObjectPtr<UAnimMontage> WeaponFireMontage;

	UPROPERTY(EditAnywhere, Category="WeaponAnimation")
	TObjectPtr<UAnimMontage> WeaponFireDownsightsMontage;

	UPROPERTY(EditAnywhere, Category="WeaponAnimation")
	TObjectPtr<UAnimMontage> WeaponFireFromCrouchWalkMontage;

	UPROPERTY(EditAnywhere, Category="WeaponAnimation")
	TObjectPtr<UAnimMontage> WeaponCockingMontage;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFXSystemComponent> BeamPSC;

	UPROPERTY(Transient)
	bool bTracerFXSupportsMultipleSimultaneousTracers;

	UPROPERTY(Transient)
	bool bTracerFXSupportsMultipleSequentialTracers;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UNiagaraComponent> TracerBeamFX;

	UPROPERTY(EditAnywhere, Category="CharacterAnimation")
	float CrouchWalkSpeedThreshold;

	UPROPERTY(EditAnywhere, Category="CharacterAnimation")
	bool bEnableRecoilDelay;

	UPROPERTY(EditAnywhere, Category="Reticle")
	float ReticleSpreadZeroingDistanceFromMuzzle;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_OverheatState)
	EFortWeaponOverheatState OverheatState;

	UPROPERTY(EditAnywhere, Category="CharacterAnimation")
	TObjectPtr<UAnimMontage> OverheatedAnimation;

	UPROPERTY(EditAnywhere, Category="WeaponAnimation")
	TObjectPtr<UAnimMontage> WeaponOverheatedAnimation;

	UPROPERTY(EditAnywhere, Category="Overheating")
	bool bCooldownWhileOverheated;

	UPROPERTY(EditAnywhere, Category="Overheating")
	bool bShouldDisplayReticleOverheatIndicator;

	UPROPERTY()
	float OverheatValue;

	UPROPERTY(Transient)
	float TimeHeatWasLastAdded;

	UPROPERTY(Replicated)
	float TimeOverheatedBegan;

	UPROPERTY(Transient, Replicated)
	FVector LWProjectile_DamageStart;

	UPROPERTY(Transient, Replicated)
	FVector LWProjectile_DamageDirection;

	UPROPERTY(Transient)
	float LWProjectile_ActivateRemovedTimestamp;

	UPROPERTY(EditAnywhere, Category="Gameplay")
	bool bCacheAimPointOnFire;

	UPROPERTY(EditAnywhere, Category="Gameplay")
	FVector CachedAimPoint;

	UPROPERTY(Transient)
	TScriptInterface<IFortAthenaAILODSettings> CachedLODSettingsManager;

private:
	UPROPERTY(Transient, Replicated)
	uint8 bUseOverrideBaseSpread : 1;

	UPROPERTY(Transient, Replicated)
	uint8 bUseOverrideSpreadDownsightsMultiplier : 1;

	UPROPERTY(Transient)
	TObjectPtr<UNiagaraSystem> BeamNiagaraSystem;

	UPROPERTY(Config)
	uint8 bUseAthenaRecoil : 1;

	UPROPERTY(Config)
	uint8 bUseAthenaPerfectADSAim : 1;

	UPROPERTY(Config)
	uint8 bFirstShotAccuracyCheckVehicleMovement : 1;

	UPROPERTY(Config)
	float FirstShotAccuracyMinWaitTime;

	UPROPERTY(Transient)
	int32 BulletCountForPerBulletRecoil;

	UPROPERTY(Transient)
	float BulletCountForPerBulletSpread;

	UPROPERTY(Transient)
	float TimeRemainingForBulletSpread;

};

